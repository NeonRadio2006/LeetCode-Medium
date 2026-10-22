// 1.Brute Force Approach
// Time:- O(N²) [N is the number of nodes]
// Space:- O(N) [Space of adjacency list(N+E) dominates where E is the number of edges]
// Checking every node as the main root of the tree
// AC
class Solution {
public:
    string getSeq(char c){
        vector<string>repeatingSeq={"RBW","BWR","WRB"};
        if(c=='R'){
            return repeatingSeq[0];
        }
        else if(c=='B'){
            return repeatingSeq[1];
        }
        return repeatingSeq[2];
    }
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        // Using an unordered map to form the adjacency list as we don't know the number of nodes
        unordered_map<int,vector<int>>adj;
        // n denotes the value of N-1
        int n=INT_MIN;
        // Forming the adjacency list
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            // Also finding the node with highest label which is n-1 
            n=max({n,u,v});
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // Visited map to ignore already visited nodes while doing a bfs
        unordered_map<int,bool>visited;
        // Checking every node as the mian root of the tree
        for(int i=0;i<=n;i++){
            // If the adjacency of this node is more than 2 then it violates the binary property
            if(adj[i].size()>2){
                continue;
            }
            // Clear the map
            visited.clear();
            // Initialize an empty queue
            queue<int>q;
            // Boolean variable to determine whether this node i is a valid root or not
            bool isValidRoot=true;
            // currIdx%3 denotes the index of the color of the nodes which are currently present in the queue in the respective repeating sequence
            int currIdx=0;
            // Determine the repeating sequence according to the starting color
            string seq=getSeq(colors[i]);
            // Push the node i
            q.push(i);
            while(!q.empty()){
                // Determine the current size of the queue
                int size=q.size();
                // Get and pop the nodes from the queue untill size becomes 0
                while(size--){
                    int currNode=q.front();
                    q.pop();
                    // Mark this node as visited
                    visited[currNode]=true;
                    // denotes the index of the color we want to appear in the children of currNode
                    int nextIdx=(currIdx+1)%3;
                    // Go through every adjacent node of currNode
                    for(int nei:adj[currNode]){
                        // Which are not visited
                        if(!visited[nei]){
                            // And if the color of the adjacent node does not match with our desired color then it is impossible
                            // Mark the boolean variable to be false and break immediately
                            if(colors[nei]!=seq[nextIdx]){
                                isValidRoot=false;
                                break;
                            }
                            // Otherwise just this node into the queue
                            q.push(nei);
                        }
                    }
                    // Pruning
                    if(!isValidRoot){
                        break;
                    }
                }
                // Pruning
                if(!isValidRoot){
                    break;
                }
                // Increase the currIdx for next level
                currIdx++;
            }
            // If there was no violation of the repeating sequence then we have found a valid root
            // Hence immediately returning it
            if(isValidRoot){
                return i;
            }
        }
        // If none of the root was valid then just return -1
        return -1;
    }
};
// 2.Optimized Approach
// Time:- O(N) [N is the number of nodes]
// Space:- O(N) [Space of adjacency list(N+E) dominates where E is the number of edges]
// AC
// We are not explicitly mentioned that the edgtes are directional bu the colors and the condition of repeating sequence act as hidden arrows
// In any of the sequence we take it can be seen that R should always appear before B and B should always appear before W and W should always appear before R
// It is like if a R and B nodes are connected it is mandatory that the node with color R is the parent and the node with color B is a child node
class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=colors.length();
        // Creating adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // We take the node 0 as root for now and we will calculate the depth of nodes wrt node 0
        vector<int>depth(n,1e9); 
        queue<int>q;
        // Depth of node 0 is considered as 0
        depth[0]=0;
        q.push(0);
        // It is to determing the node which at the minimum depth or in other words is the highest nodes
        int minDepth=0;
        int candidateRoot=0;
        // This BFS ensures that each and every node is pushed and popped, so it runs for n times
        // There are total of N-1 edges in the tree so the total time complexity of BFS is 2(N-1) which is linear
        while (!q.empty()){
            int u=q.front();
            q.pop();
            // Determine the color of current node
            char colorOfu=colors[u];
            // Go through every adjacent node to this current node
            for (int v:adj[u]){
                // If the adjacent node is already visited then just ignore it
                if(depth[v]!=1e9){
                    continue;
                }
                // Determin the color of the adjacent node
                char colorOfv=colors[v];
                // If two adjacent nodes are of same color then it is an impossible case
                if (colorOfu==colorOfv){
                    return -1;
                }
                // These determine whether the adjacent node is is the parent of our current node or child of our current node
                // We increase the depth if the adjaent node is child of our current node
                if((colorOfu=='R'&&colorOfv=='B')||(colorOfu=='B'&&colorOfv=='W')||(colorOfu=='W'&&colorOfv=='R')){
                    depth[v]=depth[u]+1;
                }
                // We decrease the depth if the adjacent node is parent of our current node
                else{
                    depth[v]=depth[u]-1; 
                }
                // If we have found node in a depth which is higher than the current highest node then modify it
                if(depth[v]<minDepth){
                    minDepth=depth[v];
                    candidateRoot=v;
                }
                // Push it to the queue
                q.push(v);
            }
        }
        // Denotes the number of roots 
        // Ther should only be one root
        int roots=0;
        // Same logic of linear time applies here also
        // Go through every node
        for(int i=0;i<n;i++){
            // Denotes the number of children this node has
            int numberOfChildren=0;
            // Denotes the number of parent this node has
            int numberOfParents=0;
            // Go through every adjacent node of node i
            for(int v:adj[i]){
                // If node v is deeper then it's a child node
                if(depth[v]==depth[i]+1){
                    numberOfChildren++;
                }
                // Otherwise v is a parent node
                else if(depth[v]==depth[i]-1){
                    numberOfParents++;
                }
            }
            // Checking for binary tree property
            if(numberOfChildren>2){
                return -1;
            }
            // Each node should have atmost one parent
            if(numberOfParents>1){
                return -1;
            }
            // If this node is at the minimum depth then this is a root
            if(depth[i]==minDepth){
                roots++;
            }
        }
        // Number of roots should be 1
        if(roots!=1){
            return -1;
        }
        // Return the root
        return candidateRoot;
    }
};

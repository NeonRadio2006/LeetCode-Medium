class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // First make the adjacency list
        vector<int>adj[n];
        for(auto& invocation:invocations){
            int a=invocation[0];
            int b=invocation[1];
            adj[a].push_back(b);
            //  Do not perform the below mentioned operation bcz we are dealing with directed edge here and this operation will make the edge bidirectional
            // adj[b].push_back(a);
        }
        // Boolen vector to quickly know if a particular node is suspicious or not
        // If isSuspicious[i] is true that means the ith node is suspicious
        vector<bool>isSuspicious(n,false);
        // Perfroming BFS from the node k to know all the suspicious node
        queue<int>q;
        q.push(k);
        isSuspicious[k]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                // For cycle detection
                if(isSuspicious[adj[node][i]]){
                    continue;
                }
                // Add this node to be suspicious as well
                isSuspicious[adj[node][i]]=true;
                q.push(adj[node][i]);
            }
        }
        // This variable helps us to decide whether we are allowed to remove only the suspicious nodes or not
        // If this variable remained true after our next operation then we can say that we can remove all the suspicious nodes
        bool onlySusNodes=true;
        // Now this visited vector is to check whether a non suspicious node has already been visited or not
        vector<bool>visited(n,false);
        // We will analayze every non-suspicious node and determine whether this node or the nodes attached directly or indirectly invokes any susppicious nodes.
        for(int i=0;i<n;i++){
            // First condition is to check whether the node is suspicious or not
            // Second condition is to check whether the node has already been visited or not,if visited then we don't need to visit it again.This saves computation.
            if(!isSuspicious[i]&&!visited[i]){
                // BFS
                queue<int>q;
                q.push(i);
                // Mark this node as true
                visited[i]=true;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int i=0;i<adj[node].size();i++){
                        // If this node invokes a suspicious node then we can't remove the suspicious nodes
                        if(isSuspicious[adj[node][i]]){
                            onlySusNodes=false;
                            break;
                        }
                        // For cycle detection
                        if(!visited[adj[node][i]]){
                            visited[adj[node][i]]=true;
                            q.push(adj[node][i]);
                        }
                    }
                    // Pruning:-Break statement to escape the while loop early
                    if(!onlySusNodes){
                        break;
                    }
                }
            }
            // Pruning:-Break statement to escape the for loop early
            if(!onlySusNodes){
                break;
            }
        }
        // Initializing the answer with emppty vector because if all the nodes are suspicious then we have to delete the whole graph
        vector<int>ans={};
        // If we can remove only the suspicious nodes,that means we have return the list of nodes which are marked as false in the isSuspicious vector.
        if(onlySusNodes){
            for(int i=0;i<n;i++){
                // If every node is suspicious then this statement never exectues
                if(!isSuspicious[i]){
                    ans.push_back(i);
                }
            }
        }
        // If we are not allowed to remove all the sus nodes that means we have to keep the graph as it is
        else{
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }
        // Returning the answer
        return ans;
    }
};

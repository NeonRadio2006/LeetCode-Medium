// Time:- O((nk + mk)log(nk)) [m denotes number of edges]
// Space:- O(nk + m)
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Initialize the adjacency list
        vector<vector<pair<int,int>>>adj(n);
        // Form the adjacency list
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
        }
        // weights[u][cnt] denotes the minimum total weight required to reach node u with cnt consecutive characters at the end of the path
        vector<vector<long long>>weights(n,vector<long long>(k+1,INT_MAX));
        // This Min-Heap stores {totalWeight,node,cnt}
        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>>pq;
        // Initialie the priority queue and the weights array
        weights[0][1]=0;
        pq.push({0,0,1});
        // Standard Dijkstra
        while(!pq.empty()){
            // Extract the current minimum state
            auto[d,u,cnt]=pq.top();
            pq.pop();
            // Optimization
            if(d!=weights[u][cnt]){
                continue;
            }
            // Explore the neighbour nodes
            for(auto& [v,w]:adj[u]){
                int ncnt;
                // If the neighbour also has the same label as our current node
                if(labels[v]==labels[u]){
                    // Then just incrment cnt by 1
                    ncnt=cnt+1;
                    // If the new cnt exceeds k then immediately discard this state
                    if(ncnt>k){
                        continue;
                    }
                }
                // Else if the neighbour has different label then reset the cnt
                else{
                    ncnt=1;
                }
                // Calculate the new weight
                long long nd=d+w;
                // If the new weight is lesser than the current weight assigned to this state
                if(nd<weights[v][ncnt]){
                    // Then update it
                    weights[v][ncnt]=nd;
                    // And push it to the queue
                    pq.push({nd,v,ncnt});
                }
            }
        }
        // Initialize the answer with INT_MAX
        int ans=INT_MAX;
        // Find the minimum answer
        for(int i=1;i<=k;i++){
            ans=min(ans,(int)weights[n-1][i]);
        }
        // If the answer remians unchanged, then return -1
        if(ans==INT_MAX){
            return -1;
        }
        // Return the final answer
        return ans;
    }
};

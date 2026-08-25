// My DSU Template
class DSU{
    vector<int>parent,rank,sizes;
    int comps;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        sizes.resize(n+1,1);
        comps=n;
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int fpar(int node){
        if(node==parent[node]){
            return node;
        }
         return parent[node]=fpar(parent[node]);
    }
    bool ubr(int u,int v){
        int p_u=fpar(u);
        int p_v=fpar(v);
        if(p_u==p_v){
            return false;
        }
        if(rank[p_u]<rank[p_v]){
            parent[p_u]=p_v;
        }
        else if(rank[p_v]<rank[p_u]){
            parent[p_v]=p_u;
        }
        else{
            parent[p_v]=p_u;
            rank[p_u]++;
        }
        comps--;
        return true;
    }
    bool ubs(int u,int v){
        int p_u=fpar(u);
        int p_v=fpar(v);
        if(p_u==p_v){
            return false;
        }
        if(sizes[p_u]<sizes[p_v]){
            parent[p_u]=p_v;
            sizes[p_v]+=sizes[p_u];
        }
        else{
            parent[p_v]=p_u;
            sizes[p_u]+=sizes[p_v];
        }
        comps--;
        return true;
    }
    bool same(int u,int v){
        return fpar(u)==fpar(v);
    }
    int getsize(int u){
        return sizes[fpar(u)];
    }
    int count(){
        return comps;
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        // Initialize dsu
        DSU dsu(n);
        // Form the connected components and make sure to do union by size
        for(auto& edge:edges){
            dsu.ubs(edge[0],edge[1]);
        }
        // Answer to return
        long long ans=0;
        // Number of nodes remaining to pair it with
        long long remNodes=n;
        for(int i=0;i<n;i++){
            // Only considering the parent nodes
            if(dsu.fpar(i)==i){
                // Get the size of the component
                long long size=dsu.getsize(i);
                // Add the contribution of this component
                ans+=size*(remNodes-size);
                // Remove this component so we don't calculate a pair twice
                remNodes-=size;
            }
        }
        // Returning the answer
        return ans;
    }
};

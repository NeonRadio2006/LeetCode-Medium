// Standard DSU template
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
    int countIslands(vector<vector<int>>& grid, int k) {
        // Number of rows in the grid
        int m=grid.size();
        // Number of columns in the grid
        int n=grid[0].size();
        // Initialize the DSU
        DSU dsu(m*n);
        // For checking all the neighbours
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        // Traversing the grid
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                // If the value at the cell is not +ve then ignore it
                if(grid[r][c]==0){
                    continue;
                }
                // If the cell represents land
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    // Then join it with neighbour lands(if any)
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]>0){
                        dsu.ubr(r*n+c,nr*n+nc);
                    }
                }
            }
        }
        // {key,value}, here key denotes the parent of the island and value denotes the sum of lands present in that island
        unordered_map<int,long long>parentsAndSums;
        // Traverse the grid to determine the usm of all the islands
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0){
                    continue;
                }
                // Determine the parent whoose island consist of this land
                int currParent=dsu.fpar(r*n+c);
                // Add the value to the parent
                parentsAndSums[currParent]+=grid[r][c];
            }
        }
        // Initialize the answer
        int ans=0;
        // Traverse the map
        for(auto& [parent,sum]:parentsAndSums){
            // Increment the answer when a sum is found which is divisible by k
            if(sum%k==0){
                ans++;
            }
        }
        // Return the final answer
        return ans;
    }
};

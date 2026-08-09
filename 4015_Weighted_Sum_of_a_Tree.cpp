class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        // Initialize the size
        int n=parent.size();
        // In this vector we will store the depth of each node
        vector<int>depths(n,-1);
        // Considering depth of root as 0
        depths[0]=0;
        // Calculating depths
        for(int i=0;i<n;i++){
            // If the depth is already calculated then ignore this node
            if(depths[i]!=-1){
                continue;
            }
            // Finding the path untill we encounter a node which has a depth != -1
            int currNode=i;
            vector<int>path;
            while(depths[currNode]==-1){
                path.push_back(currNode);
                currNode=parent[currNode];
            }
            // Note this depth
            int currDepth=depths[currNode];
            // Set depths of each node just by incrementing the currDepth at every level
            while(!path.empty()){
                currDepth++;
                depths[path.back()]=currDepth;
                path.pop_back();
            }
        }
        // The height of the tree will just be the maximum depth
        int h=*max_element(depths.begin(),depths.end());
        // Long Long variable to store the answer
        long long ans=0;
        // Calculating the answer
        for(int i=0;i<n;i++){
            ans+=(long long)nums[i]*(h-depths[i]+1);
        }
        // Returning the answer
        return ans;
    }
};

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // Initialize the size of nums
        int n=nums.size();
        // Finding minimum and maximum elements
        int mn=1e6;
        int mx=-1e6;
        // Also finding the indices of the min and max element
        int mnIdx=-1,mxIdx=-1;
        // As nums contain distinct integers there can only be one mn and mx
        for(int i=0;i<n;i++){
            if(nums[i]<mn){
                mn=nums[i];
                mnIdx=i;
            }
            if(nums[i]>mx){
                mx=nums[i];
                mxIdx=i;
            }
        }
        // There can only be 3 possibilities:-
        // Remove from front untill both mn and mx are not removed and note the number of operations required
        // Remove from back untill both mn and mx are not removed and note the number of operations required
        // Remove from front untill the element is removed which appears before among mn and mx + Remove from back untill the element is not removed which appears later maong mn and mx
        // Find minimum of all these 3 possibilities and that will be our answer
        int ans=min({max(mnIdx,mxIdx)+1,n-min(mnIdx,mxIdx),min(mnIdx,mxIdx)+1+n-max(mnIdx,mxIdx)});
        // Returning the answer
        return ans;
    }
};

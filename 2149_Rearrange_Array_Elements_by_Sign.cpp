class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Initialize the size of nums
        int n=nums.size();
        // Answer array to return
        vector<int> ans(n);
        // Denotes current indices where +ve and -ve elements are to be placed
        int posIndex=0;
        int negIndex=1;
        // Traverse
        for(int i=0;i<n;i++){
            // If the current element is negative then place this element at index 'negIndex'
            if(nums[i]<0){
                ans[negIndex]=nums[i];
                // Then increment negIndex by 2
                negIndex+=2;
            }
            // If the current element is positive then place this element at index 'posIndex'
            else{
                ans[posIndex]=nums[i];
                // Then increment posIndex by 2
                posIndex+=2;
            }
        }
        // Return the answer
        return ans;
    }
};

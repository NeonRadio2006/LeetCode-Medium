class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find the rightmost index i where nums[i]<nums[i+1]
        int ind=-1,n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        // If there is no such index then it means we have the largest permutation
        // Just reverse the given nums
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        // Replace the element at index 'ind' with the first greater element from the right
        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        // Then just reverse the elements fro ind+1 to n-1 to make the permutation even smaller
        reverse(nums.begin()+ind+1,nums.end());
    }
};

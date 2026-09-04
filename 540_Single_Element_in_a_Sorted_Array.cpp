// 1.Do it in oiner time using freq map
// 2.Do it in liner time by taking XOR of all elements
// 3.Optimal Approach
// Using BS
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Initialize the size of nums
        int n=nums.size();
        // Handling the edge cases
        if(n==1){return nums[0];}
        if(nums[0]!=nums[1]){return nums[0];}
        if(nums[n-2]!=nums[n-1]){return nums[n-1];}
        int low=1;
        int high=n-2;
        while(low<=high){
            // Find mid
            int mid=low + (high-low)/2;
            // If element at mid is not equal to any of it's neighbours then this is our answer
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            // A single element can mess up the parity of pairs
            // If the parity is ok,then our answer must be right of mid
            else if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
                low=mid+1;
            }
            // Else answer is in left of mid
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};

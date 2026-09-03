// 1.Brute Force Approach
// Use any sorting algo of O(nlogn)
// 2.Better Approach
// Count number of 0's and 1's as cnt0 and cnt1 resp and then replace first cnt0 positions with 0,then cnt1 positions with 1 and rest of it with 2
// 3.Optimal Approach
// DNF Algo
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // This divides the array into 4 regions
        // i) In the range [0...low-1] all elements are 0
        // ii) In the range [low...mid-1] all elements are 1
        // iii) In the range [mid...high] is the unsorted range which is needed to sorted out
        // iv) In the range [high+1..n-1] all elements are 2
        // Initially the whole array is unsorted
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        // Till the unsorted range exists
        while(mid<=high){
            // If element at index 'mid' is 0,then it should be at the index 'low'
            if(nums[mid]==0){
                // Swap it with nums[low]
                swap(nums[low],nums[mid]);
                // Then increment low and mid pointer
                low++;
                mid++;
            }
            // If element at index 'mid' is 1,then we can include it in the 2nd range just by incrementing the mid pointer
            else if(nums[mid]==1){
                mid++;
            }
            // If the element at index 'mid' is 2,then it should be at the index 'high'
            else{
                // Swap it with nums[high]
                swap(nums[mid],nums[high]);
                // Then decrement the high pointer
                high--;
            }
        }
    }
};

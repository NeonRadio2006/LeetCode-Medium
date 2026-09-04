// 1.Do it in linear time
// 2.Optimal Approach
// Modified BS
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            // Find the mid
            int mid = left + (right - left) / 2;
            // Going Dwonhill
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            // Going uphill 
            else {
                left = mid + 1;
            }
        }
        return left;        
    }
};

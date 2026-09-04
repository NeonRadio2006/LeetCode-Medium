// 1.Do it in liner timr
// 2.Optimal Approach
// Modified BS
class Solution {
public:
     bool searchRotated(vector<int>& arr,int target,int n){
        int low=0;
        int high=n-1;
        while(low<=high){
            // Find mid
            int mid=low+(high-low)/2;
            // If we found the target then immediately return true
            if(arr[mid]==target){
                return true;
            }
            // When we can't determine which half is sorted
            if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                low=low+1;
                high=high-1;
                continue;
            }
            // Left half is sorted
            else if(arr[low]<=arr[mid]){
                // Target lies within low and mid
                if(arr[low]<=target && target<=arr[mid]){
                    high=mid-1;
                }
                // If it doesn't
                else{
                    low=mid+1;
                }
            }
            // Right half is sorted
            else{
                // Target lies within mid and high
                if(arr[mid]<=target && target<=arr[high]){
                    low=mid+1;
                }
                // If it doesn't
                else{
                    high=mid-1;
                }
            }
        }
        // Return false if element does not exists
        return false;
    }
    bool search(vector<int>& nums, int target) {
        return searchRotated(nums,target,nums.size());
    }
};

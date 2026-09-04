// 1.Search it in linear time
// 2.Optimal Appraoch
// Modified BS
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            // Find mid
            int mid=low + (high-low)/2;
            // If we already found the target then return it
            if(arr[mid]==target){
                return mid;
            }
            // If left part is sorted
            else if(arr[low]<=arr[mid]){
                // If target lies in that range
                if(arr[low]<=target && target<=arr[mid]){
                    high=mid-1;
                }
                // If target does not lie 
                else{
                    low=mid+1;
                }
            }
            // If right part is sorted
            else{
                // If target lies in that target
                if(arr[mid]<=target && target<=arr[high]){
                    low=mid+1;
                }
                // If target does not lie
                else{
                    high=mid-1;
                }
            }
        }
        // Return -1 if element does not exists
        return -1;
    }
};

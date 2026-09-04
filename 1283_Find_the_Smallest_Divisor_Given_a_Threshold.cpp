// 1.Brute Force Approach
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // Find the max element in nums
        int mx=*max_element(nums.begin(),nums.end());
        // Try every divisor from 1 to mx
        for(int d=1;d<=mx;d++){
            // What will be the sum if we divide every number by this d
            int sum=0;
            for(int x:nums){
                // Ceil
                sum+=(x+d-1)/d;
            }
            // As we wanted the smallest d
            // As soon as we get a valid d return it
            if(sum<=threshold){
                return d;
            }
        }
        return -1;
    }
};
// 2.Optimal Approach
class Solution {
public:
    bool possible(int d,int limit,vector<int>&nums){
        int sum=0;
        for(int x:nums){
            sum+=(x+d-1)/d;
            if(sum>limit){
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // Find the max element in nums
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<high){
            // Find mid
            int m=low+(high-low)/2;
            // If mid is a possible answer
            // Try for more smaller d
            if(possible(m,threshold,nums)){
                high=m;
            }
            // If not then try for a bigger d
            else{
                low=m+1;
            }
        }
        // Final answer will be stored in low
        return low;
    }
};

// 1.Brute Force Approach
// O(n³)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize the size and the answer
        int n=nums.size();
        int ans=INT_MIN;
        // Determine the end points of the subarray
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                // Sum for this subarray
                int sum=0;
                // Calculate the sum of this subarray
                for(int k=i;k<=j;k++){
                    sum+=nums[k];
                }
                // Update the answer
                ans=max(ans,sum);
            }
        }
        // Return the answer
        return ans;
    }
};
// 2.Slightly Better Approach
// O(n²)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize the size and the answer
        int n=nums.size();
        int ans=INT_MIN;
        // Determine the end points of the subarray
        for(int i=0;i<n;i++){
            // Sum for subarray starting from this index
            int sum=0;
            // Calculate sum till jth index then update the answer on the go
            for(int j=i;j<n;j++){
                sum+=nums[j];
                ans=max(ans,sum);
            }
        }
        // Return the answer
        return ans;
    }
};
// 3.Better Approach
// O(nlogn)
class Solution {
public:
    // Using Divide And Conquer Technique
    // For an array the max subarray can be either totally in left/right half or crosses the middle
    int find(int l,int h,vector<int>&nums){
        // Base Case:- When size of the subproblem is 1
        if(l==h){
            return nums[l];
        }
        // Find the mid
        int m=l+(h-l)/2;
        // Best subarray is in left half
        int bestLeft=find(l,m,nums);
        // Best Subarray is in right half
        int bestRight=find(m+1,h,nums);
        // The max sum we can get from the left part
        int leftSum=0;
        int sum=0;
        for(int i=m;i>=l;i--){
            sum+=nums[i];
            leftSum=max(leftSum,sum);
        }
        // The max sum we can get from the right part
        int rightSum=0;
        sum=0;
        for(int i=m+1;i<=h;i++){
            sum+=nums[i];
            rightSum=max(rightSum,sum);
        }
        // Best subarray crosses mid
        int bestMid=leftSum+rightSum;
        // Return the maximum among the 3 choices
        return max({bestLeft,bestRight,bestMid});
    }
    int maxSubArray(vector<int>& nums) {
        return find(0,nums.size()-1,nums);
    }
};
// 4.Optimal Approach(Kadane's Algo)
// O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        // Traverse the array
        for(int i=0;i<nums.size();i++){
            // If question says to find the subarray also:-
            //if(sum==0){
                //start=i;
            //}  
            // Add the current element to the running sum
            sum=sum+nums[i];
            // If sum s greater than maxi then update maxi
            if(sum>maxi){
                maxi=sum;
                // If question says to find the subarray also:-
                //ansStart=start;  
                //ansEnd=i;        
            }
            // If sum becomes negative then discard that running sum and reset it to 0
            if(sum<0){
                sum=0;
            }
        }
        // Return maxi
        return maxi;
    }
};

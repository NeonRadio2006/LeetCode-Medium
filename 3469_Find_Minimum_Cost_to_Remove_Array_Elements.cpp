// There are 4 codes:-
// 1.Pure Recursive Solution
class Solution {
public:
    int find(int i,int prevIndex,vector<int>&nums){
        // If i goes out of bound that means only one element is remaing and that will be stored in prev
        if(i>=nums.size()){
            return nums[prevIndex];
        }
        // This means that we only have 2 elements left to process,so just return the max among both of them
        if(i+1>=nums.size()){
            return max(nums[prevIndex],nums[i]);
        }
        // Now the 3 elemensts we have in the front are a=nums[prevIndex],b=nums[i] and c=nums[i+1]
        // We have 3 possibilities,which are either keep a,b or c
        // We have to try every possibility
        // After removing 2 elements next index would be i+2
        int aAndb=max(nums[prevIndex],nums[i])+find(i+2,i+1,nums);
        int bAndc=max(nums[i],nums[i+1])+find(i+2,prevIndex,nums);
        int aAndc=max(nums[prevIndex],nums[i+1])+find(i+2,i,nums);
        // Returning the minimum cost among the 3 possibilities for this state
        return min({aAndb,bAndc,aAndc});
    }
    int minCost(vector<int>& nums) {
        // If array size is 1,then just return the element present in the array
        if(nums.size()==1){
            return nums[0];
        }
        // If the array size is 2,then just return max of both the numbers
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        // Otherwise find the answer using recursion
        return find(1,0,nums);
    }
};
// 2.Memoized Solution(Top-Down)
class Solution {
public:
    int find(int i,int prevIndex,vector<int>&nums,vector<vector<int>>&dp){
        // If i goes out of bound that means only one element is remaing and that will be stored in prev
        if(i>=nums.size()){
            return nums[prevIndex];
        }
        // This means that we only have 2 elements left to process,so just return the max among both of them
        if(i+1>=nums.size()){
            return max(nums[prevIndex],nums[i]);
        }
        // If we have already calculated the answer for this state,then return it immediately
        if(dp[i][prevIndex]!=-1){
            return dp[i][prevIndex];
        }
        // Now the 3 elemensts we have in the front are a=nums[prevIndex],b=nums[i] and c=nums[i+1]
        // We have 3 possibilities,which are either keep a,b or c
        // We have to try every possibility
        // After removing 2 elements next index would be i+2
        int aAndb=max(nums[prevIndex],nums[i])+find(i+2,i+1,nums,dp);
        int bAndc=max(nums[i],nums[i+1])+find(i+2,prevIndex,nums,dp);
        int aAndc=max(nums[prevIndex],nums[i+1])+find(i+2,i,nums,dp);
        // Returning and storing the minimum cost among the 3 possibilities for this state
        return dp[i][prevIndex]=min({aAndb,bAndc,aAndc});
    }
    int minCost(vector<int>& nums) {
        // If array size is 1,then just return the element present in the array
        if(nums.size()==1){
            return nums[0];
        }
        // If the array size is 2,then just return max of both the numbers
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        // Otherwise find the answer using recursion + memoization
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return find(1,0,nums,dp);
    }
};
// 3.Tabulated Solution(Bottom-Up)
class Solution {
public:
    int minCost(vector<int>& nums) {
        // If array size is 1,then just return the element present in the array
        if(nums.size()==1){
            return nums[0];
        }
        // If the array size is 2,then just return max of both the numbers
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        // Otherwise find the asnwer 
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size(),-1));
        // Handling the first base case,that is for i>=nums.size()
        for(int prevIndex=0;prevIndex<nums.size();prevIndex++){
            dp[nums.size()][prevIndex]=nums[prevIndex];
        }
        // Handling the second base case,that is for i+1>=nums.size()
        // prevIndex can only go upto nums.size()-2 as we have 2 elements
        for(int prevIndex=0;prevIndex<nums.size()-1;prevIndex++){
            dp[nums.size()-1][prevIndex]=max(nums[prevIndex],nums[nums.size()-1]);
        }
        // Now the cases for i=nums.size() and i=nums.size()-1 are handled
        for(int i=nums.size()-2;i>=1;i--){
            // Now update the value for ith index considering every possible index from 0 to (i-1) as prevIndex
            for(int prevIndex=0;prevIndex<i;prevIndex++){
                int aAndb=max(nums[prevIndex],nums[i])+dp[i+2][i+1];
                int bAndc=max(nums[i],nums[i+1])+dp[i+2][prevIndex];
                int aAndc=max(nums[prevIndex],nums[i+1])+dp[i+2][i];
                dp[i][prevIndex]=min({aAndb,bAndc,aAndc});
            }
        }
        // Returning the answer
        return dp[1][0];
    }
};
// 4.Space Optimized Solution
class Solution {
public:
    int minCost(vector<int>& nums) {
        // If array size is 1,then just return the element present in the array
        if(nums.size()==1){
            return nums[0];
        }
        // If the array size is 2,then just return max of both the numbers
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        // We just need two previous vectors
        vector<int>prev2(nums.size(),0);
        vector<int>prev1(nums.size(),0);
        // Handling the first base case,that is for i>=nums.size()
        // This will be stored in prev2 initially
        for(int prevIndex=0;prevIndex<nums.size();prevIndex++){
            prev2[prevIndex]=nums[prevIndex];
        }
        // Handling the second base case,that is for i+1>=nums.size()
        // prevIndex can only go upto nums.size()-2 as we have 2 elements
        // This will stored in prev1 initially
        for(int prevIndex=0;prevIndex<nums.size()-1;prevIndex++){
            prev1[prevIndex]=max(nums[prevIndex],nums[nums.size()-1]);
        }
        // Now the cases for i=nums.size() and i=nums.size()-1 are handled
        for(int i=nums.size()-2;i>=1;i--){
            // For calculating the current row
            vector<int>curr(nums.size(),0);
            // Now update the value for ith index considering every possible index from 0 to (i-1) as prevIndex
            for(int prevIndex=0;prevIndex<i;prevIndex++){
                int aAndb=max(nums[prevIndex],nums[i])+prev2[i+1];
                int bAndc=max(nums[i],nums[i+1])+prev2[prevIndex];
                int aAndc=max(nums[prevIndex],nums[i+1])+prev2[i];
                curr[prevIndex]=min({aAndb,bAndc,aAndc});
            }
            prev2=prev1;
            prev1=curr;
        }
        // Returning the answer
        // The answer would be stored in the prev1 vector as for the last index we assigned the curr array as prev1 array
        return prev1[0];
    }
};

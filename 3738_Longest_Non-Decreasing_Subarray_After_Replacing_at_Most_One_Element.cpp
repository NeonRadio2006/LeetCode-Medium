class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        // If size of the input is 1 thrn answer is always 1
        if(n==1){
            return 1;
        }
        // dpl[i] denotes the length of the longest non-decreasing subarray ending at index i
        // dpr[i] denotes the length of the longest non-decreasing subarray starting at index i
        vector<int>dpl(n),dpr(n);
        // Forming the dpl array
        dpl[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1]){
                dpl[i]=dpl[i-1]+1;
            }
            else{
                dpl[i]=1;
            }
        }
        // Forming the dpr array
        dpr[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>=nums[i]){
                dpr[i]=dpr[i+1]+1;
            }
            else{
                dpr[i]=1;
            }
        }
        // Initializing the array
        int ans=0;
        // Finding the answer if we do 0 replacement
        for(int x:dpl){
            ans=max(ans,x);
        }
        // Finding answer if we do 1 replacement
        for(int i=0;i<n;i++){
            // If there is no left neighbour then join with only the right neighbour
            if(i==0){
                ans=max(ans,1+dpr[1]);
                continue;
            }
            // If there is no right neighbour then join with only left neighbour
            if(i==n-1){
                ans=max(ans,1+dpl[n-2]);
                continue;
            }
            // if we can join with both left and right neighbour
            if(nums[i-1]<=nums[i+1]){
                ans=max(ans,dpl[i-1]+1+dpr[i+1]);
            }
            // Both neighbours exist but we can join with only any one of them
            else{
                ans=max(ans,1+dpl[i-1]);
                ans=max(ans,1+dpr[i+1]);
            }
        }
        // Returning the answer
        return ans;
    }
};

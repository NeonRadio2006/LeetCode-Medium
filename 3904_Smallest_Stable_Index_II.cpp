class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // Initialize the size of nums
        int n=nums.size();
        // pmx[i] denotes the maximum element in the range [0...i]
        // smn[i] denotes the minimum element in the range [i...n-1]
        vector<int>pmx(n),smn(n);
        // Calculating prefix max
        pmx[0]=nums[0];
        for(int i=1;i<n;i++){
            pmx[i]=max(pmx[i-1],nums[i]);
        }
        // Calculating suffix min
        smn[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            smn[i]=min(smn[i+1],nums[i]);
        }
        // Finding the smallest stable index
        for(int i=0;i<n;i++){
            if(pmx[i]-smn[i]<=k){
                return i;
            }
        }
        // Returning -1 when there is no stable index in nums
        return -1;
        // We can also avoid pmx array.Instead we can maintain a running max when we are finding the answer
    }
};

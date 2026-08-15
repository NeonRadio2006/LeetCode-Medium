class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // Initialize the size of the array
        int n=nums.size();
        // Initialize the total xor
        // We will find the total xor of the whole array
        int totalXor=0;
        // Boolean variable to check if every element is 0 or there exist an element which is non zero
        bool hasNonZero=false;
        // So the main logic is that first we will find the total xor of the whole array
        // Then if the total xor is non zero,then we can just return n
        // If total xor is 0 then the answer is 0 if and only if when all the elements are 0,otherwise we can always remove a non zero element from the sequence and answer will be n-1
        for(int x:nums){
            if(x>0){
                hasNonZero=true;
            }
            totalXor^=x;
        }
        // If total xor is non zero 
        if(totalXor!=0){
            return n;
        }
        // If all elements are 0
        if(!hasNonZero){
            return 0;
        }
        // Returning n-1 if both the above cases don't execute
        return n-1;
    }
};

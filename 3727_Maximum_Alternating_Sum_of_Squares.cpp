class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // Convert every number to it's magnitude as we are going to sort it later and the -ve numbers with higher magnitude will come at the start
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        // Sort the modified vector
        sort(nums.begin(),nums.end());
        // Now from the given relation of score we can determine that the squares of elements which are present at the odd indices in the final arrangement are going to get subtracted
        // And as we have to increase the score,we want the the squares getting subtracted to be as small as possible
        // Hence we are counting how many odd indices are present in the array
        int oddi=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==1){
                oddi++;
            }
        }
        // Initialize the answer with 0
        long long ans=0;
        // Subtract the squares of all the elements which are going to be in odd indices in the final arrangement
        // We will greedily put smaller numbers in odd indices
        for(int i=0;i<oddi;i++){
            ans-=(nums[i]*nums[i]);
        }
        // Then add the squares of rest of the numbers
        for(int i=oddi;i<nums.size();i++){
            ans+=(nums[i]*nums[i]);
        }
        // Return the final answer 
        return ans;
    }
};

//Two pointer
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // Initialize the answer
        int ans=0;
        // Taking the left pointer
        int l=0;
        // Unordered Map to store the frequency
        unordered_map<int,int>freq;
        // Moving the right pointer
        // Consider 'i' as right pointer
        for(int i=0;i<nums.size();i++){
            // Whenever new element is encountered we increase the frequency
            freq[nums[i]]++;
            // If the frequency becomes more than k,then this window is invlaid and hence needed to be shrinked from left
            while(freq[nums[i]]>k){
                freq[nums[l]]--;
                l++;
            }
            // Finding the maximum length
            ans=max(ans,i-l+1);
        }
        // Returning the answer
        return ans;
    }
};

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // Frequency map
        unordered_map<int,int>freq;
        int ans=0;
        // Answer to return
        for(int x:nums){
            // Number to pair x with
            int other=k-x;
            // If we can make the pair then make it
            if(freq[other]>0){
                freq[other]--;
                // Increment the answer
                ans++;
            }
            // If we can't make a pair,then just increment the frequency of x in the map for future use
            else{
                freq[x]++;
            }
        }
        // Returning the answer
        return ans;
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Initializing the size of both the arrays
        int n=nums1.size();
        int m=nums2.size();
        // Map to recorde frequency of each element in nums2
        unordered_map<int,int>freq;
        // Final answer to be calculated
        long long ans=0;
        // Calculating the frequency
        for(int i=0;i<m;i++){
            freq[nums2[i]]++;
        }
        // Traversing nums1
        for(int x:nums1){
            // If the element is not divisible by k then it forms no pair
            if(x%k!=0){
                continue;
            }
            // If it is divisible then divide it
            x/=k;
            // Find the freq of each divisior and add it to our answer
            for(int i=1;i*i<=x;i++){
                if(x%i==0){
                    ans+=freq[i];
                    if(i!=x/i){
                        ans+=freq[x/i];
                    }
                }
            }
        }
        // Returning the final answer
        return ans;
    }
};

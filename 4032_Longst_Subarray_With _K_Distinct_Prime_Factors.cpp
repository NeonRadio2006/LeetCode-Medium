class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        // Initializing the size of the nums array
        int n=nums.size();
        // Finding the max value in the given nums array using STL
        int mx=*max_element(nums.begin(),nums.end());
        // Prep that is needed to be done before preprocessing:-
        // Vector to store smallest prime factor(spf) for a particular number
        // In other words we are finding the smallest prime factor which divides an element
        vector<int>spf(mx+1);
        // Initialize every value of the spf with itself
        for(int i=0;i<=mx;i++){
            spf[i]=i;
        }
        // Finding spf for every number
        for(int i=2;i*i<=mx;i++){
            // If spf is currently the number itself...
            if(spf[i]==i){
                // And the spf for every multiple of this number...
                for(int j=i*i;j<=mx;j+=i){
                    // Is also the multiple itself...
                    if(spf[j]==j){
                        // Then assign this number as thier spf
                        spf[j]=i;
                    }
                }
            }
        }
        // Preprocessing step:-
        // Storing all the distinct prime factors for every element in our given nums array
        vector<vector<int>>distinctFactors(n);
        for(int i=0;i<n;i++){
            // Get that number
            int x=nums[i];
            //While that number is greater than 1,that means it is still a product of prime numbers
            while(x>1){
                // Find the spf for the current number x
                int p=spf[x];
                // Add this to vector at index i
                distinctFactors[i].push_back(p);
                // Remove all occurences of this prime form x
                while(x%p==0){
                    x/=p;
                }
            }
        }
        // Now the sliding window starts:-
        // Initialize the freq array,this will helps us determine how many distinct prime numbers are there in the subarray
        vector<int>freq(mx+1,0);
        // Initialize the left pointer,number of distinct primes and the final answer
        int l=0,distinct=0,ans=0;
        // Traversing the nums array
        // Consider i as the right pointer
        for(int i=0;i<n;i++){
            // Add this current element to the window
            // What do we mean by adding the element to the window?
            // Means that we have to increment the frequencies of every distinct prime factor this number has with also checking that does this number introduces a new prime number
            for(int p:distinctFactors[i]){
                // If the freq of the prime factor is 0 that means we have got a new prime number for this subarray,hence incrementing the number of distinct primes
                if(freq[p]==0){
                    distinct++;
                }
                // Incrementing the freq of the prime number
                // This will always happen no matter if this number has appeared for the first time or not
                freq[p]++;
            }
            // Now what if we have more than k distinct primes in our current window?
            // We remove the elements from the left
            // What do we mean by removing the element from the window?
            // Means that we have to decrement the frequencies of every distinct prime factor this number has with also checking that does after decrementing is there an element with freq as 0
            while(distinct>k){
                for(int p:distinctFactors[l]){
                    // Decrementing the freq of this prime factor
                    freq[p]--;
                    // If freq becomes 0 that means we have to decrement the number of distinct primes
                    if(freq[p]==0){
                        distinct--;
                    }
                }
                // Incrementing the left pointer untill number of distinct prime number in the window becomes lesser than or equal to k
                l++;
            }
            // Calculating the answer every time 
            ans=max(ans,i-l+1);
        }
        // Returning the answer 
        return ans;
    }
};

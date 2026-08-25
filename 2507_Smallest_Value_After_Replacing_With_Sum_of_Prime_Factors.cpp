class Solution {
public:
    int smallestValue(int n) {
        // Special edge case for n==4 as the new n that will be calculated from 4 will also be 4(only case of loop)
        if(n==4){
            return 4;
        }
        // Standard way of calculating the spf
        vector<int>spf(n+1);
        for(int i=0;i<=n;i++){
            spf[i]=i;
        }
        for(int i=2;i*i<=n;i++){
            if(spf[i]==i){
                for(int j=i*i;j<=n;j+=i){
                    if(spf[j]==j){
                        spf[j]=i;
                    }
                }
            }
        }
        // Initializing the answer with n
        int ans=n;
        // Looping till n is a composite number
        while(spf[n]!=n){
            // Variable to calculate the sum of all prime factors of current n,as many time as they occur
            int currSum=0;
            // Calculating the sum
            while(n>1){
                int p=spf[n];
                currSum+=p;
                n/=p;
            }
            // Assigning thie sum as the new n for next iteration
            n=currSum;
            // Finding the minimum encounterd n
            ans=min(ans,n);
        }
        // Returning the answer
        return ans;
    }
};

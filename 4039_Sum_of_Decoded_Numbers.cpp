class Solution {
public:
    // Initialize the MOD
    const int MOD=1e9 + 7;
    // Modular Binary Exponentiation
    long long power(long long b,long long e){
        long long res=1;
        while(e>0){
            if(e&1){
                res=(res*b)%MOD;
            }
            b=(b*b)%MOD;
            e>>=1;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        // Initializing the answer
        long long ans=0;
        for(long long x:nums){
            // Calculate the width
            long long width=x%10;
            // Calculate di
            long long di=x/10;
            // Convert di to string to get xi and yi easily
            string s=to_string(di);
            // Convert first 'width' digits of di as xi
            long long xi=stoll(s.substr(0,width));
            // Convert rest of the digis as yi
            long long yi=stoll(s.substr(width));
            // Compute the xi to the power yi and add it to the answer
            // Don't forget to tale the MOD
            ans=(ans+power(xi,yi))%MOD;
        }
        // Returning the answer,typecasted back to int as the function type is int
        return (int)ans;
    }
};

// 1.Brute Force Approach
// Check for every substring
class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int>freq(26,0);
                int mn=n+1,mx=0;
                for(int k=i;k<=j;k++){
                    freq[s[k]-'a']++;
                    mx=max(mx,freq[s[k]-'a']);
                }
                for(int l=0;l<26;l++){
                    if(freq[l]>0){
                        mn=min(mn,freq[l]);
                    }
                }
                ans+=(mx-mn);
            }
        }
        return ans;
    }
};
// 2.Optimal Approach
class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int mn=n+1,mx=0;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        mx=max(mx,freq[k]);
                        mn=min(mn,freq[k]);
                    }
                }
                ans+=(mx-mn);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        // Length of the given binary string
        int n=s.length();
        // Map to preprocess the the binary string and to calculate the earliest position
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            // If the current character is 0 then we do not want to start from here, but we should consider it as 0 and record it's earliest appearance
            if(s[i]=='0'){
                if(!mp.count(0)){
                    mp[0]={i,i};
                }
                continue;
            }
            // Calculating num
            int num=0;
            // As we are going to only have those numbers which lesser than or equaL to 1e9 which fits in 30 bits only, so from each index i we will only examine maximum of length 30 substring
            for(int j=i;j<min(n,i+30);j++){
                // Constructing num character by character
                num=(num<<1)|(s[j]-'0');
                // If this does not exist in map then store the occurence of it
                if(!mp.count(num)){
                    mp[num]={i,j};
                }
            }
        }
        // Answer to return
        vector<vector<int>>ans;
        // Finding answer for each query
        for(auto& query:queries){
            // Val will the XOR of first and second
            int val=query[0]^query[1];
            // If it exists in map then push the occurence in the answer
            if(mp.count(val)){
                ans.push_back({mp[val].first,mp[val].second});
            }
            // And if it does not then push {-1,-1}
            else{
                ans.push_back({-1,-1});
            }
        }
        // Returning the answer
        return ans;
    }
};

// 1.Brute Force Approach
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // Initialize the ans with an empty string
        string ans="";
        // Try every substring
        for(int i=0;i<s.length();i++){
            // Count number of ones in the substring starting from ith index
            int ones=0;
            for(int j=i;j<s.length();j++){
                // If the jth characte is '1',then increment the count of ones
                if(s[j]=='1'){
                    ones++;
                }
                // If the count has exceeded k,we can just break out from this inner loop
                if(ones>k){
                    break;
                }
                // If we have found a substing with exactly k ones in it
                if(ones==k){
                    // Extract this substring
                    string curr=s.substr(i,j-i+1);
                    // If our answer is currently empty,then we can assign our extracted string directly as answer
                    if(ans.empty()){
                        ans=curr;
                    }
                    // If our current answer is not empty and is longer than our extracted string then we should assign it as our new answer
                    else if(curr.length()<ans.length()){
                        ans=curr;
                    }
                    // If the lengths are same then we have to take care of lexicographical order
                    // If our current answer is lexicographically bigger than our extracted string then in this case also we should assign it as our new answer
                    else if(curr.length()==ans.length()){
                        if(curr<ans){
                            ans=curr;
                        }
                    }
                    // If none of the cases match we can just continue with our further iterations
                    else{
                        continue;
                    }
                }
            }
        }
        // Returning the answer
        return ans;
    }
};
// 2.Prefix + Unordered Map Approach
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // Initializing the length of the string as n
        int n=s.length();
        // Initialize the ans with an empty string
        string ans="";
        // Making prefix array wrt to number of ones
        vector<int>prefixOnes(n,0);
        // Calculating the prefix array
        if(s[0]=='1'){
            prefixOnes[0]=1;
        }
        for(int i=1;i<n;i++){
            prefixOnes[i]+=prefixOnes[i-1];
            if(s[i]=='1'){
                prefixOnes[i]++;
            }
        }
        // Unorderd map to store the last index of a number where it appeared
        unordered_map<int,int>lastIdxOf;
        // Doing this bcz if the prefix array does not contain a 0 in it but contains k in it then we might miss some cases
        // If the prefix array contains a 0 in it then it will overwrite -1 anyways in our loop
        lastIdxOf[0]=-1;
        // Loop to calculate the last index where a number appeared
        for(int i=0;i<n;i++){
            lastIdxOf[prefixOnes[i]]=i;
        }
        // Traversing from backwards
        int eIdx=n-1;
        // Loop untill eIdx is valid and have more than or equal to k ones as a prefix at that position
        while(eIdx>=0&&prefixOnes[eIdx]>=k){
            int onesTillHere=prefixOnes[eIdx];
            // Have to see whether this 'check' apperas somewhere or not in the map
            int check=prefixOnes[eIdx]-k;
            // If appears
            if(lastIdxOf.find(check)!=lastIdxOf.end()){
                // The next index of the stored index will be considered as starting index
                int sIdx=lastIdxOf[check]+1;
                // Assigning answer accordingly
                // We are extracting string only when necessary
                if(ans.empty()){
                    ans=s.substr(sIdx,eIdx-sIdx+1);
                }
                else if((sIdx,eIdx-sIdx+1)<ans.length()){
                    ans=s.substr(sIdx,eIdx-sIdx+1);
                }
                else if((sIdx,eIdx-sIdx+1)==ans.length()){
                    string curr=s.substr(sIdx,eIdx-sIdx+1);
                    if(curr<ans){
                        ans=curr;
                    }
                }
            }
            // Decrementing the end index
            eIdx--;
        }
        // Returning the answer
        return ans;
    }
};
// 3.Sliding Window Approach
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // Initializing the length of the string as n
        int n=s.length();
        // Initialize the ans with an empty string
        string ans="";
        // Initializing the left pointer and count of ones
        int left=0;
        int ones=0;
        // Consider i as right pointer
        for(int i=0;i<n;i++){
            // If the current character is 1 then increment the count of ones
            if(s[i]=='1'){
                ones++;
            }
            // If count of ones has exceeded k then shrink the window size by incrementing the left pointer and decrementing the count of ones accordingly
            while(ones>k){
                if(s[left]=='1'){
                    ones--;
                }
                left++;
            }
            // We have found a window with exactly k ones
            if(ones==k){
                // Remove any unwanted 0's from the front to make the length more shorter
                while(s[left]=='0'){
                    left++;
                }
                // Etract the curr string
                string curr=s.substr(left,i-left+1);
                // Assign it to ans accordingly
                if(ans.empty()){
                    ans=curr;
                }
                else if(curr.length()<ans.length()){
                    ans=curr;
                }
                else if(curr.length()==ans.length()){
                    if(curr<ans){
                        ans=curr;
                    }
                }
            }
        }
        // Returning the answer
        return ans;
    }
};

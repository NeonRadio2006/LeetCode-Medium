// 1.Brute Force Approach
// Time:-O(n³)
// Space:-O(1)
class Solution {
public:
    // Standard function to check if a string is a palindrome or not
    bool isPal(int l,int r,string&s){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        // Initialize the length of s
        int n=s.length();
        // Initialize the final length of the answer with 1
        int ansLen=1;
        // And it's start index with 0
        int ansSIdx=0;
        // Check every pair of i and j
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                // Whether the substring s[l...r] is a palindrome or not
                if(isPal(i,j,s)){
                    // If yes then,determine it's length
                    int len=j-i+1;
                    // If length of current substring is greater thant the length of our current answer
                    if(len>ansLen){
                        // Then assign length of current string as length of answer string
                        ansLen=len;
                        // And store it's start index
                        ansSIdx=i;
                    }
                }
            }
        }
        // Return the appropriate substring
        return s.substr(ansSIdx,ansLen);
    }
};
// 2.Memoized Approach
// Time:-O(n²)
// Space:-O(n²)+O(n) recursion stack space
class Solution {
public:
    // Recursive function to check if a string is a palindrome or not
    bool isPal(int l,int r,string&s,vector<vector<int>>&dp){
        if(l>=r){
            return true;
        }
        // Check if this state has already be evaluated or not
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        if(s[l]!=s[r]){
            return false;
        }
        // Store answer for this result 
        return dp[l][r]=isPal(l+1,r-1,s,dp);
    }
    string longestPalindrome(string s) {
        // Initialize the length of s
        int n=s.length();
        // Initialize  2D-DP array
        vector<vector<int>>dp(n,vector<int>(n,-1));
        // Initialize the final length of the answer with 1
        int ansLen=1;
        // And it's start index with 0
        int ansSIdx=0;
        // Check every pair of i and j
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                // Whether the substring s[l...r] is a palindrome or not
                if(isPal(i,j,s,dp)){
                    // If yes then,determine it's length
                    int len=j-i+1;
                    // If length of current substring is greater thant the length of our current answer
                    if(len>ansLen){
                        // Then assign length of current string as length of answer string
                        ansLen=len;
                        // And store it's start index
                        ansSIdx=i;
                    }
                }
            }
        }
        // Return the appropriate substring
        return s.substr(ansSIdx,ansLen);
    }
};
// 3.Tabulated Approach
// Time:-O(n²)
// Space:-O(n²)
class Solution {
public:
    string longestPalindrome(string s) {
        // Initialize the length of s
        int n=s.length();
        // Initialize 2D-DP array
        // dp[i][j] denotes if s[i...j] is a palindrome or not
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        // Initialize the final length of the answer with 1
        int ansLen=1;
        // And it's start index with 0
        int ansSIdx=0;
        // Base Case translation
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        // As we need i+1 and j-1 for dp[i][j],so we will move backwards with i and forward with j
        for(int i=n-2;i>=0;i--){
            // As we have already handled length 1 case,Hence starting from j from i+1 and not from i
            for(int j=i+1;j<n;j++){
                // If character at i and j are same
                if(s[i]==s[j]){
                    // And if they are adjacent OR thne inner part is a palindrome then s[i...j] is also a palindrome
                    if(j-i==1||dp[i+1][j-1]){
                        dp[i][j]=true;
                    }
                }
                // If s[i...j] is a palindrome
                if(dp[i][j]){
                    // Get it's length
                    int len=j-i+1;
                    // Compare it with the current largest length
                    // And if bigger
                    if(len>ansLen){
                        // Then assign this length as answer length 
                        ansLen=len;
                        // Also store the starting index
                        ansSIdx=i;
                    }
                }
            }
        }
        // Return the appropriate substring
        return s.substr(ansSIdx,ansLen);
    }
};
// 4.Space Optimized Approach
// Time:-O(n²)
// Space:-O(2n)
class Solution {
public:
    string longestPalindrome(string s) {
        // Initialize the length of s
        int n=s.length();
        // Initialize 1D-DP arrays
        // prev[j] denotes dp[i+1][j]
        // curr[j] denotes dp[i][j]
        vector<bool>prev(n,false);
        vector<bool>curr(n,false);
        // Initialize the final length of the answer with 1
        int ansLen=1;
        // And it's start index with 0
        int ansSIdx=0;
        // As we need i+1 and j-1 for dp[i][j],so we will move backwards with i and forward with j
        for(int i=n-2;i>=0;i--){
            // Fill with false for current row
            fill(curr.begin(),curr.end(),false);
            // This will translate to dp[i][i] which was base case,Hence it is true
            curr[i]=true;
            // As we have already handled length 1 case,Hence starting from j from i+1 and not from i
            for(int j=i+1;j<n;j++){
                // If character at i and j are same
                if(s[i]==s[j]){
                    // And if they are adjacent OR thne inner part is a palindrome then s[i...j] is also a palindrome
                    if(j-i==1||prev[j-1]){
                        curr[j]=true;
                    }
                }
                // If s[i...j] is a palindrome
                if(curr[j]){
                    // Get it's length
                    int len=j-i+1;
                    // Compare it with the current largest length
                    // And if bigger
                    if(len>ansLen){
                        // Then assign this length as answer length 
                        ansLen=len;
                        // Also store the starting index
                        ansSIdx=i;
                    }
                }
            }
            // Assign this curr as prev for next iteration
            prev=curr;
        }
        // Return the appropriate substring
        return s.substr(ansSIdx,ansLen);
    }
};
// 5.Better Space Optimized Approach
// Time:-O(n²)
// Space:-O(n)
class Solution {
public:
    string longestPalindrome(string s) {
        // Initialize the length of s
        int n=s.length();
        // Initialize 1D-DP array
        // For current i dp[j] shows whether s[i...j] is a palindrome or not
        // A the start of row i dp[j] represents dp[i+1][j]
        vector<bool>dp(n,false);
        // Initialize the final length of the answer with 1
        int ansLen=1;
        // And it's start index with 0
        int ansSIdx=0;
        // As we need i+1 and j-1 for dp[i][j],so we will move backwards with i and forward with j
        for(int i=n-2;i>=0;i--){
            // As we need j-1 and if we traverse backwards then the j-1 will be untounched
            for(int j=n-1;j>=i;j--){
                // If character at i and j are same
                if(s[i]==s[j]){
                    // And if they are adjacent OR the inner part is a palindrome then s[i...j] is also a palindrome
                    if(j-i<=1){
                        dp[j]=true;
                    }
                    else{
                        dp[j]=dp[j-1];
                    }
                }
                else{
                    dp[j]=false;
                }
                // If s[i...j] is a palindrome
                if(dp[j]){
                    // Get it's length
                    int len=j-i+1;
                    // Compare it with the current largest length
                    // And if bigger
                    if(len>ansLen){
                        // Then assign this length as answer length 
                        ansLen=len;
                        // Also store the starting index
                        ansSIdx=i;
                    }
                }
            }
        }
        // Return the appropriate substring
        return s.substr(ansSIdx,ansLen);
    }
};
// 6.Expand from center Approach
// Time:-O(n²)
// Space:-O(1)
class Solution {
public:
    int expand(int l,int r,string&s){
        while(l>=0&&r<s.length()&&s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        // Initialize the length of s
        int n=s.length();
        // Initialize the final length of the answer with 1
        int ansLen=1;
        // And it's start index with 0
        int ansSIdx=0;
        // Expand from every index as center of palindrome for odd length
        // Expand from i and i+1 for even length palindrome
        for(int i=0;i<n;i++){
            int oddLen=expand(i,i,s);
            int evenLen=expand(i,i+1,s);
            // Find max of both length
            int mxLen=max(oddLen,evenLen);
            // If length of current substring is greater thant the length of our current answer
            if(mxLen>ansLen){
                ansLen=mxLen;
                // Find starting index
                if(oddLen>=evenLen){
                    ansSIdx=i-oddLen/2;
                }
                else{
                    ansSIdx=i-evenLen/2+1;
                }
            }
        }
        // Return the appropriate substring
        return s.substr(ansSIdx,ansLen);
    }
};
// 7.Manacher's Algo
// Time:-O(n)
// Space:-O(n)
// In this we will only talk about odd length palindromes and converting even length palindromes to odd length
// Insert # after every character of string and also add an extra # at the starting making string look like #s[0]#s[1]#s[2]#...#s[n-1]#.Let's call this modified string as t
// Length of t will be 2n+1 where n is the length of s
// Take every character of this string as center and expand
// If character is an alphabet that means we are currently considering an odd length palindrome
// If character is # that means we are currently considering an even length palindrome
// Now we will make an extra array p of same size as t.
// p[i] will show the maximum length of suffix starting from (i-1) which is a mirror image of prefix of same length starting at (i+1) OR
// Maximum length of palindrome if ith character of string t is the center(Let's call that length as k)
// Now if we expand for each character then it will again result in quadratic time complexity
// Now consider indices of t as [0...l..j....x....i..r...2n]
// Now it is said that the substring from l to r is a palindrome centered at x and this is a rightmost palindromic substring
// Rightmost palindromic substring means that it has the largest r among all the palindromic substring we have seen
// j is the mirror image of i which means dist between l and j is same as the dist between i and r
// Now we have to find p[i] and we are assuming that we already have calculated p[0],p[1],...,p[i-1].That is j-l=r-i => j=l+(r-i)
// Now as j<i that means we already have p[j]
// Case 1 => j-p[j]>l:-
// Then p[i]=p[j] as both are mirror image and insider of a big palindrome so they have to have identical palindromes
// Case 2 => j-p[j]<=l:-
// Then p[i]>=p[j] bcz we have not seen the character at index r+1 even once,bcz of this there might be a chance to form a bigger palindrome with center as i
// p[i] will be aleast p[j] so we will initialize our expansion after length r-i 
// Imp thing to  note is that these two cases are only valid when i<r
// Otherwise we have start a fresh new expansion form index i
class Solution {
public:
    string longestPalindrome(string s) {
        // Making the string t
        string t="#";
        for(char c:s){
            t+=c;
            t+="#";
        }
        // Length of string t
        int n=t.length();
        // Boundaries of rightmost palindromic substring
        int l=0;
        int r=-1;
        // Centre of rightmost palindromic substring
        int x;
        // Length of the longest palindromic substring
        int ansLen=0;
        // Array p of same size as t
        vector<int>p(n);
        // We can't expans from the first character so p[0] will be 0
        p[0]=0;
        for(int i=1;i<n;i++){
            int k;
            // If i>r then start a new expansion
            if(i>r){
                k=0;
            }
            else{
                // Find the position of j
                int j=l+(r-i);
                // Case 1
                if(j-p[j]>l){
                    p[i]=p[j];
                    continue;
                }
                // Case 2
                else{
                    k=r-i;
                }
            }
            // Expand
            while(i-k>=0&&i+k<n&&t[i-k]==t[i+k]){
                k++;
            }
            // Decrement k by 1 as we the last iteration of the while loop incremented k by 1
            k--;
            // Assign this k as p[i]
            p[i]=k;
            // Update if the length is greater
            if(p[i]>ansLen){
                ansLen=p[i];
                // Update the centre
                x=i/2;
            }
            // Update the right and left boundaries if possible
            if(i+k>r){
                l=i-k;
                r=i+k;
            }
            // You might think that there is a while loop inside a for loop then this should be O(n²),but we will proove that while loop executes atmost n times during entire execution
            // The proof heavily depends upon 'r'
            // Now observe the while loop,we are comparing characters and there are only two possible result for that whaich is either the characters match or a mismatch
            // Now as a mismatch occurs the while loop breaks,so we can say that for each iteration of outer loop there can be atmost one mismatch hence at most n mismatches
            // Now if it's a match then either the length of palndrome centerd at i becomes longer than ansLen after expansion or remains lesser than or equal to ansLen
            // In any case r remains either same or increases
            // r never decreases and there can be only n values possible for r at max
        }
        // Return the appropriate substring
        return s.substr(x-(ansLen/2),ansLen);
    }
};

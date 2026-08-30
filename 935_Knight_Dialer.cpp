// 1.Pure Recursive Solution(TLE)
class Solution {
public:
    // MOD to be taken
    const int MOD=1e9 + 7;
    // Recursive function to find the answer
    int find(int digit,int length,int n,vector<vector<int>>&mp){
        // If the length becomes equal to n then we have found a number
        // Hence return 1
        if(n==length){
            return 1;
        }
        // Otherwise initialize the answer with 0
        int ans=0;
        // Try every possible next digit
        // Get possible digits for next position form the mp
        for(int nextDigit:mp[digit]){
            // Length increases by 1
            // Don't forget to take MOD
            ans=(ans+find(nextDigit,length+1,n,mp))%MOD;
        }
        // Return the answer for this state
        return ans;
    }
    int knightDialer(int n) {
        // The vector at ith index shows which digit we can go to from i
        vector<vector<int>>mp={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        // Initialize the answer
        int ans=0;
        // Any digit can be placed on the first position
        for(int i=0;i<=9;i++){
            ans=(ans+find(i,1,n,mp))%MOD;
        }
        // Returning the answer
        return ans;
    }
};
// 2.Memoized Solution
class Solution {
public:
    // MOD to be taken
    const int MOD=1e9 + 7;
    // Recursive function to find the answer
    int find(int digit,int length,int n,vector<vector<int>>&mp,vector<vector<int>>&dp){
        // If the length becomes equal to n then we have found a number
        // Hence return 1
        if(n==length){
            return 1;
        }
        //If the answer for this digit with this much remaing length has already been calculated then immediately return it
        if(dp[digit][length]!=-1){
            return dp[digit][length];
        }
        // Otherwise initialize the answer with 0
        int ans=0;
        // Try every possible next digit
        // Get possible digits for next position form the mp
        for(int nextDigit:mp[digit]){
            // Length increases by 1
            // Don't forget to take MOD
            ans=(ans+find(nextDigit,length+1,n,mp,dp))%MOD;
        }
        // Storing and returning the answer for this state
        return dp[digit][length]=ans;
    }
    int knightDialer(int n) {
        // The vector at ith index shows which digit we can go to from i
        vector<vector<int>>mp={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        // Initialize the answer
        int ans=0;
        // Initialize the dp table
        vector<vector<int>>dp(10,vector<int>(n+1,-1));
        // Any digit can be placed on the first position
        for(int i=0;i<=9;i++){
            ans=(ans+find(i,1,n,mp,dp))%MOD;
        }
        // Returning the answer
        return ans;
    }
};
// 3.Tabulated Solution
class Solution {
public:
    // MOD to be taken
    const int MOD=1e9 + 7;
    int knightDialer(int n) {
        // The vector at ith index shows which digit we can go to from i
        vector<vector<int>>mp={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        // Initialize the answer
        int ans=0;
        // Initialize the dp table
        vector<vector<int>>dp(10,vector<int>(n+1,0));
        // Translating the base case of the recursion
        for(int i=0;i<=9;i++){
            dp[i][n]=1;
        }
        // Calculating from length=n-1 down to 1
        for(int length=n-1;length>=1;length--){
            // Trying every digit with their...
            for(int digit=0;digit<=9;digit++){
                // All possible nextDigit
                for(int nextDigit:mp[digit]){
                    // Don't forget to take MOD
                    dp[digit][length]=(dp[digit][length]+dp[nextDigit][length+1])%MOD;
                }
            }
        }
        // Any digit can be placed on the first position
        for(int i=0;i<=9;i++){
            ans=(ans+dp[i][1])%MOD;
        }
        // Returning the answer
        return ans;
    }
};
// 4.Space Optimized Solution
class Solution {
public:
    // MOD to be taken
    const int MOD=1e9 + 7;
    int knightDialer(int n) {
        // The vector at ith index shows which digit we can go to from i
        vector<vector<int>>mp={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        // Initialize the answer
        int ans=0;
        // Represents the dp[nextDigit][length+1]
        // Initialized with 1 (Base Case)
        vector<int>next(10,1);
        // Calculating from length=n-1 down to 1
        for(int length=n-1;length>=1;length--){
            // Represent dp[digit][length]
            vector<int>curr(10,0);
            // Trying every digit with their...
            for(int digit=0;digit<=9;digit++){
                // All possible nextDigit
                for(int nextDigit:mp[digit]){
                    // Don't forget to take MOD
                    curr[digit]=(curr[digit]+next[nextDigit])%MOD;
                }
            }
            // Assign this curr as next for the upcoming iteration
            next=curr;
        }
        // Any digit can be placed on the first position
        for(int i=0;i<=9;i++){
            ans=(ans+next[i])%MOD;
        }
        // Returning the answer
        return ans;
    }
};
// 5.Matrix Exponentiation
class Solution {
public:
    const int MOD=1e9 + 7;
    vector<vector<int>> multiply(vector<vector<int>>&A,vector<vector<int>>&B){
        vector<vector<int>>C(10,vector<int>(10,0));
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    C[i][j]=(C[i][j]+1LL*A[i][k]*B[k][j])%MOD;
                }
            }
        }
        return C;
    }
    vector<vector<int>> power(vector<vector<int>>& A, int n) {
        // Identity matrix
        vector<vector<int>>result(10,vector<int>(10,0));
        for(int i=0;i<10;i++){
            result[i][i]=1;
        }
        while(n>0){
            if(n%2==1){
                result=multiply(result,A);
            }
            A=multiply(A,A);
            n/=2;
        }
        return result;
    }
    int knightDialer(int n) {
        vector<vector<int>>mp={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        // Transition matrix
        vector<vector<int>>matrix(10,vector<int>(10,0));
        for(int digit=0;digit<10;digit++){
            for(int nextDigit:mp[digit]){
                matrix[digit][nextDigit]=1;
            }
        }
        // We need to make n-1 moves
        matrix=power(matrix,n - 1);
        int ans=0;
        // Any digit can be the starting digit
        for(int start=0;start<10;start++){
            for(int end=0;end<10;end++){
                ans=(ans+matrix[start][end])%MOD;
            }
        }
        return ans;
    }
};

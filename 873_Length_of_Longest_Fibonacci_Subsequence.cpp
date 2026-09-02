// Given:-Ther will be given an integer array arr
// Constraints:-arr.length ∈ [3,1000],arr[i] ∈ [1,1e9].arr will be strictly increasing
// To Do:-Find the length of longest Fibonacci Subsequence
// 1.Brute Force Approach
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        // To store the first and last position of an element 
        unordered_map<int,int>firstPosOf;
        unordered_map<int,int>lastPosOf;
        // Storing positions
        for(int i=0;i<n;i++){
            if(firstPosOf.find(arr[i])==firstPosOf.end()){
                firstPosOf[arr[i]]=i;
            }
            lastPosOf[arr[i]]=i;
        }
        // Final answer to return
        int ans=INT_MIN;
        // Checking every pair of i and j
        // We are checking the length of subsequence we can make if the elements arr[i] and arr[j] are the starting two elements
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                // Storing i and j in k and l as we have to keep modifying these indices
                int k=i;
                int l=j;
                // Length we can form from these two starting element
                int currLen=2;
                // While l is a valid index
                while(l<n){
                    // If l is the last index,there is no further element
                    // So just update the answer and break from the while loop
                    if(l==n-1){
                        ans=max(ans,currLen);
                        break;
                    }
                    // Finding which element is needed next
                    int sum=arr[k]+arr[l];
                    auto it=firstPosOf.find(sum);
                    // If this next element is present in the array and it appears after l then we can include it in our subsequence
                    if(it!=firstPosOf.end()&&lastPosOf[sum]>l){
                        // Increment the length
                        currLen++;
                        // Move the k pointer to l
                        k=l;
                        // Move the l pointer to the position of next element
                        l=lastPosOf[sum];
                    }
                    // If we can't continue with this subsequence anymore than just update the answer and break from the loop
                    else{
                        ans=max(ans,currLen);
                        break;
                    }
                }
                // This might look O(n³) solution but it is not
                // We are jumping big steps when we are moving the k and l pointers
                // Sequences which are of Fibonacci nature grows really really fast
                // So the time complexity boils down to O(n²log(M)) where M denotes the max value in arr.Hence this code passes.
            }
        }
        // Check if answer is atleast 3 or not
        if(ans<3){
            return 0;
        }
        // Returning the answer
        return ans;
    }
};
// 2.Optimal Approach
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        // To store positions of elements
        unordered_map<int,int>posOf;
        for(int i=0;i<n;i++){
            posOf[arr[i]]=i;
        }
        // dp[i][j] denotes the length of the fibonacci subsequence ending at arr[i] as the second last and arr[j] as the last element of the subsequence
        // Initially every pair will have 2 as max length
        vector<vector<int>>dp(n,vector<int>(n,2));
        // Final answer to return
        int ans=0;
        // Checking every pair as second last and last element
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // The element just before arr[i]
                int prevElement=arr[j]-arr[i];
                // If that element is present..
                if(posOf.count(prevElement)){
                    // And is before arr[i]..
                    if(posOf[prevElement]<i){
                        // Then we can increase the length of the subsequence
                        dp[i][j]=dp[posOf[prevElement]][i]+1;
                    }
                }
                // Updating the asnwer on the go
                ans=max(ans,dp[i][j]);
            }
        }
        // Check if answer is atleast 3 or not
        if(ans<3){
            return 0;
        }
        // Returning the answer
        return ans;
    }
};

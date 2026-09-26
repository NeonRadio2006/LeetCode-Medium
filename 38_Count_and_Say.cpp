// 1.Recursive Method
// Time:- O(nL)
// Space:- O(L)
// Auxillary Space: O(n)
class Solution {
public:
    // Function to find RLE of a string
    string runLengthEncodingOf(string& ans){
        // This string will denote the RLE of ans
        string rle="";
        // Initialize the start and end pointer
        int s=0,e=1;
        // Loop until end pointer points to a valid index
        while(e<ans.length()){
            // If character at previous index does not match with the character at end pointer that means we have found a new character, and before moving forward we need to encode prev character
            if(ans[e]!=ans[e-1]){
                // Append it's frequency
                rle+=to_string(e-s);
                // Append the character itself
                rle+=ans[e-1];
                // Move the start pointer for future
                s=e;
            }
            // Increment the end pointer
            e++;
        }
        // Encode the last character
        rle+=to_string(e-s);
        rle+=ans[ans.length()-1];
        // Return the RLE of ans
        return rle;
    }
    string find(int n){
        // Base Case
        if(n==1){
            return "1";
        }
        // Call this function recursively
        string ans=find(n-1);
        // Return the RLE of ans
        return runLengthEncodingOf(ans);
    }
    string countAndSay(int n) {
        // Call the helper function
        return find(n);
    }
};
// 2.Iterative Method
// Time:- O(nL)
// Space:- O(L)
class Solution {
public:
    // Function to find RLE of a string
    string runLengthEncodingOf(string& ans){
        // This string will denote the RLE of ans
        string rle="";
        // Initialize the start and end pointer
        int s=0,e=1;
        // Loop until end pointer points to a valid index
        while(e<ans.length()){
            // If character at previous index does not match with the character at end pointer that means we have found a new character, and before moving forward we need to encode prev character
            if(ans[e]!=ans[e-1]){
                // Append it's frequency
                rle+=to_string(e-s);
                // Append the character itself
                rle+=ans[e-1];
                // Move the start pointer for future
                s=e;
            }
            // Increment the end pointer
            e++;
        }
        // Encode the last character
        rle+=to_string(e-s);
        rle+=ans[ans.length()-1];
        // Return the RLE of ans
        return rle;
    }
    void find(int c,int n,string& ans){
        // We will loop until our counter c is lesser than n
        while(c<=n){
            // If c==1, that means it is countAndSay(1) and we know that this is the base case which gives "1"
            if(c==1){
                ans+="1";
            }
            // If c!=1, that means we need RLE of countAndSay(c-1) which will be the current answer
            else{
                ans=runLengthEncodingOf(ans);
            }
            // Increment the counter c
            c++;
        }
    }
    string countAndSay(int n) {
        // Initialize the empty answer string
        string ans="";
        // Call the helper function
        find(1,n,ans);
        // Return the final answer
        return ans;
    }
};

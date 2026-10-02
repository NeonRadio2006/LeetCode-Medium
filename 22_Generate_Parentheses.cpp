// Time:- O(n*²ⁿCₙ/n+1) [n*Cₙ where Cₙ is the catalan number] 
// Space:- O(n*Cₙ + 2n) [space of output + recursion stack space]
// Total number of valid strings is equal to the nth catalan number
class Solution {
public:
    // Backtracking code to find all the answers
    void find(int n,vector<string>& ans,string &temp,int s){
        // When size of temp becomes 2n
        if(temp.size()==2*n){
            // And the score is 0, that means w have found a valid parentheses
            if(s==0){
                // Push this temp to the answer
                ans.push_back(temp);
                // And return from here
                return;
            }
            // If the score is not 0 that means the current temp is invalid
            return;
        }
        // If score becomes -ve or more than n then it is an invalid path
        if(s<0 || s>n){
            return;
        }
        // Push a ( bracket
        temp.push_back('(');
        // Try every possibility
        find(n,ans,temp,s+1);
        // Backtrack
        temp.pop_back();
        // Push a ) bracket
        temp.push_back(')');
        // Try every possibility
        find(n,ans,temp,s-1);
        // Backtrack
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        // Initialize empty 2D vector of string
        vector<string>ans;
        // Each valid parentheses have to start with a ( character
        string temp="(";
        // Score to determine whether the string is valid or not
        int score=1;
        // Find all the strings
        find(n,ans,temp,score);
        // Returning the answer
        return ans;
    }
};

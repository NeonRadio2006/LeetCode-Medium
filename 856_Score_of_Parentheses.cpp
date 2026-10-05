class Solution {
public:
    int scoreOfParentheses(string s) {
        // Initialize the total score and current depth with 0
        int totalScore=0;
        int depth=0;
        // Traverse the string
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                // Moving one layer deeper
                depth++;
            }
            else{
                // Moving one layer outwards
                depth--;    
                // If the previous character was '(', we found a core "()"
                if(s[i-1]=='('){
                    // It contributes 2^depth to the total score.
                    // We use bitwise left-shift (1<<depth) for fast calculating powers of 2 in O(1).
                    totalScore+=(1<<depth);
                }
            }
        }
        return totalScore;
    }
};

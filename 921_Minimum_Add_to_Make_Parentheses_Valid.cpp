// Time:- O(n)
// Space:- O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        // Initialize the final answer with 0
        int ans=0;
        // Initialize the score with 0
        // We will increment the score when we encounter an openeing bracket and will decrement it when we encounter a closing bracket
        int score=0;
        for(char c:s){
            // Increment the score
            if(c=='('){
                score++;
            }
            else{
                // Decrement the score
                score--;
                // Check whether score has become -ve
                // If it has become negative that menas we have closing bracket(s) with no mathcing opening ones
                if(score<0){
                    // Hence increment the answer to balance out the number of opeing and closing brackets
                    ans++;
                    // Reset the score to 0
                    score=0;
                }
            }
        }
        // Add the score to 0
        // We can't just calculate the score and return it as the score denotes the difference between the number of opening and closing brackets
        // If we just returned the absolute value of the score then the sequence ")(" will also give answer as 0 but we need 2 brakcets to add to make it a valid sequence
        ans+=score;
        // Return the final ans
        return ans;
    }
};

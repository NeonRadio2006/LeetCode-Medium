class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Handling the impossible case
        if(sum>9*num){
            return "";
        }
        // Initialize the answer with empty string
        string ans="";
        // To maximize the score we would greedily add as much 9 as we could such that sum of digits is exactly sum
        int nines=sum/9;
        int rem=sum%9;
        // Append all the nines into the answer
        // We are appending all the 9's first bcz we also have to ensure that the resulting integer is the largest
        ans+=string(nines,'9');
        // If the remainder is +ve then append that
        if(rem>0){
            ans+=char('0'+rem);
        }
        // Now append 0's
        ans+=string(num-ans.length(),'0');
        // Return the final answer
        return ans;
    }
};

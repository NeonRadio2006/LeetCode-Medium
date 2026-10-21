// 1.Direct Simulation
// Time:-O(nlogn) [Due to sorting]
// Space:-O(n) [Due to making copy of the input string]
// There can only be 4 possible answers, which are 0,1,2,3
class Solution {
public:
    int minOperations(string s) {
        // Determine the length of the input string
        int n=s.length();
        // If the string is already sorted or is of unit length then we require 0 moves
        if(is_sorted(s.begin(),s.end())||n==1){
            return 0;
        }
        // If the string is not sorted and is of length 2, then it is not possible to sort the string by using any number of moves
        if(n==2){
            return -1;
        }
        // Make two copies of the original input string
        string t1=s,t2=s;
        // Initialize answer variables with 0
        int ans1=0,ans2=0;
        // Select the first copy t1 and...
        // Sort all the characters except the first one as we can not select the whole string
        sort(t1.begin()+1,t1.end());
        // If the first character is already smaller than or equal to the character after it then the string is sorted and answer is 1 
        if(t1[0]<=t1[1]){
            ans1=1;
        }
        // If the 1st character is greater than the 2nd character and lesser than or equal to the last character then we would select the substring from the 1st character to the last and sort it
        // Hence answer will be 2  
        else if(t1[1]<t1[0]&&t1[0]<=t1[n-1]){
            ans1=2;
        }
        // If the 1st character is greater then the last character then again select the substring from 1st character to last character and sort it
        // This will make the 1st character to become the last second character and then we will sort the last second and last character which will sort the whole string
        // Hence answer will be 3
        else{
            ans1=3;
        }
        // Select the second copy t2 and...
        // Sort all the characters except the last one as we can not select the whole string
        sort(t2.begin(),t2.end()-1);
        // If last second character is already smaller than or equal to the last character then the string is sorted
        // Hence answer will be 1
        if(t2[n-1]>=t2[n-2]){
            ans2=1;
        }
        // If the last character is greater than or equal to the 1st one and smaller then the last second one then select the substring from 2nd character to last character and sort it
        // Hence answer wil be 2
        else if(t2[0]<=t2[n-1]&&t2[n-1]<t2[n-2]){
            ans2=2;
        }
        // If the last character is smaller than the 1st one then select the substring starting from 2nd character to the last and sort it
        // This will make the last character to become as the new 2nd character and then we will sort the 1st and 2nd character which will sort the whole string
        // Hence answer will be 3
        else{
            ans2=3;
        }
        // At the end we will take the minimum of answers from both possibility as we have to return minimum number of moves
        return min(ans1,ans2);
    }
};
// 2.Optimized Code
// Time:-O(n) [Due to searching the smallest and largest character and also for checking if the initial string is sorted or not]
// Space:-O(1) [No copies were created]
class Solution {
public:
    int minOperations(string s) {
        // Determine the length of the input string
        int n=s.length();
        // If the string is already sorted or is of unit length then we require 0 moves
        if(is_sorted(s.begin(),s.end())){
            return 0;
        }
        // If the string is not sorted and is of length 2, then it is not possible to sort the string by using any number of moves
        if(n==2){
            return -1;
        }
        // Get the smallest and the largest character of the string
        char mn=*min_element(s.begin(),s.end());
        char mx=*max_element(s.begin(),s.end());
        // Case 1:- When answer is 1
        // If the smallest character is the 1st character OR if the largest character is the last character then answer would be 1
        // As we will just select the rest of string as substring that is either [1...n-1] OR [0...n-2] ans sort it and the final string will be sorted
        if(s[0]==mn||s[n-1]==mx){
            return 1;
        }
        // Case 2:- When answer is 2
        // If any of character at the indices 1...n-2 is equal to the smallest OR the largest one and 1st and last ar enot smallest and largest respectively then answer will be 2
        // As if the character is equal to the smallest then we will select [0...i] and sort it, and the last character is still not the largest but the first one is surely the smallest
        // So we will select [1...n-1] and sort it
        // Similarly if the character is equal to the largest then we will select [i...n-1] and sort it, and the 1st character is still not the smallest one but the last one is surely largest
        // So we will select [0...n-2] and sort it
        for(int i=1;i<n-1;i++){
            if(s[i]==mn||s[i]==mx){
                return 2;
            }
        }
        // If answer is neither 1 not 2 then the only possible answer left is 3
        return 3;
    }
};

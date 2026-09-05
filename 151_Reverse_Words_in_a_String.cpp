// 1.First Approach
// Same code can be used with deque and stack instead vector.But we would not require to reverse in deque and stack as we did in vector
class Solution {
public:
    string reverseWords(string s) {
        // Vector to store all the words
        vector<string>words;
        // Length of input string
        int n=s.length();
        // Traversing the input string
        int i=0;
        while(i<n){
            // Skip the spaces
            while(i<n&&s[i]==' '){
                i++;
            }
            // If i became n then break
            if(i==n){
                break;
            }
            // Starting index of a word
            int startIdx=i;
            // Increment i untill we encounter a space
            while(i<n&&s[i]!=' '){
                i++;
            }
            // Extract the word
            words.push_back(s.substr(startIdx,i-startIdx));
        }
        // Reverse all the words
        reverse(words.begin(),words.end());
        // Initialize empty ans string
        string ans;
        // Add all the words in ans with spaces
        for(string& word:words){
            if(!ans.empty()){
                ans+=' ';
            }
            ans+=word;
        }
        // Returning the answer
        return ans;
    }
};
// 2.Optimal Approach
class Solution {
public:
    string reverseWords(string s) {
        // Initialize empty string as answer
        string ans;
        // Traversing from back
        int i=s.length()-1;
        while(i>=0){
            // Skip the spaces
            while(i>=0&&s[i]==' '){
                i--;
            }
            // Break if we have traversed the whole string
            if(i<0){
                break;
            }
            // Ending index of the word
            int endIdx=i;
            // Finding and extracting the word
            while(i>=0&&s[i]!=' '){
                i--;
            }
            string word=s.substr(i+1,endIdx-i);
            // Add this word to answer
            if(!ans.empty()){
                ans+=' ';
            }
            ans+=word;
        }
        // Returning the answer
        return ans;
    }
};

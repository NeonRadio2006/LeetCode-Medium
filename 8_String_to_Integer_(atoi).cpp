// Direct Simulation
class Solution {
public:
    int myAtoi(string s) {
        // Initialize the length
        int n=s.length();
        // Traverse the string
        int i=0;
        // Ignore the spaces
        while(i<n&&s[i]==' '){
            i++;
        }
        // Determine the sign
        // Initially assume it as +ve
        int sign=1;
        if(i<n&&(s[i]=='+'||s[i]=='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        // Use long long to easily handle the overflow condition
        long long num=0;
        // Check if index is valid or not and the character is a digit or not
        while(i<n&&isdigit(s[i])){
            // Make the number
            num=num*10+(s[i]-'0');
            // Handle the overflow
            if(sign==1&&num>(long long)INT_MAX){
                return INT_MAX;
            }
            if(sign==-1&&-num<(long long)INT_MIN){
                return INT_MIN;
            }
            // Increment i
            i++;
        }
        // Returning the answer with it's sign
        return (int)num*sign;
    }
};

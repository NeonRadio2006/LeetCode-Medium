// 1.Brute Force
// Time:-O(n²)
// Space:-O(1)
// TLE
class Solution {
public:
    // Boolean function to determine whether a number x is prime or not
    bool isPrime(int x){
        // If x gets divided by a number smaller than itself, then it means x is not a prime number
        for(int i=2;i<x;i++){
            if(x%i==0){
                // Return false if x gets divided
                return false;
            }
        }
        // Otherwise return true
        return true;
    }
    int countPrimes(int n) {
        // Initialize the answer
        int ans=0;
        // Checking each number whether they are prime or not
        for(int i=2;i<n;i++){
            // If the number is prime..
            if(isPrime(i)){
                // Then increment the answer
                ans++;
            }
        }
        // Return the final answer
        return ans;
    }
};
// 2.Improved Brute Force
// Time:-O(n√n)
// Space:-O(1)
// TLE
class Solution {
public:
    // Boolean function to determine whether a number x is prime or not
    bool isPrime(int x){
        // If x gets divided by a number smaller than itself, then it means x is not a prime number
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                // Return false if x gets divided
                return false;
            }
        }
        // Otherwise return true
        return true;
    }
    int countPrimes(int n) {
        // Initialize the answer
        int ans=0;
        // Checking each number whether they are prime or not
        for(int i=2;i<n;i++){
            // If the number is prime..
            if(isPrime(i)){
                // Then increment the answer
                ans++;
            }
        }
        // Return the final answer
        return ans;
    }
};
// 3.Sieve of Eratosthenes
// Time:-O(nlog(log(n)))
// Space:-O(n)
// ACCEPTED
// Have to optimize the standard sieve by ignoring the even numbers as it was giving TLE
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        // Initialize a boolean vector
        vector<bool>isPrime(n,true);
        // Optimized sieve
        // Avoiding all the even numbers
        for(int i=3;i*i<n;i+=2){
            if(isPrime[i]){
                for(int j=i*i;j<n;j+=2*i){
                    isPrime[j]=false;
                }
            }
        }
        // Initialize the answer
        int ans=1;
        for(int i=3;i<n;i+=2){
            if(isPrime[i]){
                ans++;
            }
        }
        // Return the final answer
        return ans;
    }
};

class Solution {
public:
    // Q1.How does one state transition to it's next state?
    // Ans) Divide every element in the array by 2 and the array obtained will be the next state
    // Q2.How is the answer calculated for current state?
    // Ans) The answer that it's next state gives + the number of odds in the array
    // Q3.What does a state return as answer to it's previous state?
    // Ans) The current state calculate the answer for itself, let's say that answer as res then it will return res+1 to it's parent/previous state
    // Q4.What is base case and what does it return?
    // Ans) Base case is when the array only contains 1 and 0 as it's element. The base case returns the number of 1s in the array
    bool onlyOneAndZeros(vector<int>&nums){
        for(int x:nums){
            if(x>1){
                return false;
            }
        }
        return true;
    }
    int find(vector<int>&nums){
        if(onlyOneAndZeros(nums)){
            int sum=0;
            for(int x:nums){
                sum+=x;
            }
            return sum;
        }
        int currOdds=0;
        vector<int>next=nums;
        for(int &x:next){
            currOdds+=x&1;
            x/=2;
        }
        int nextAns=find(next);
        return nextAns+currOdds+1;
    }
    int minOperations(vector<int>& nums) {
        return find(nums);
    }
};

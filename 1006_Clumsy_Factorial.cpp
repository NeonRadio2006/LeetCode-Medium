// 1.Directly Simulating the procedure
class Solution {
public:
    int clumsy(int n) {
        // Hardcoding for some cases
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(n==3){
            return 6;
        }
        // Stage1 stores the initial condition that is  just numbers from n to 1 writtn in decreasing order
        vector<int>stage1(n,0);
        int toAssign=n;
        for(int i=0;i<n;i++){
            stage1[i]=toAssign;
            toAssign--;
        }
        // Now in the actual process we first multiply
        // So stage 2 stores the condition of our expression when we perform only the multiplication
        vector<int>stage2;
        int i=0;
        while(i<n){
            // Every 4th number gets multiplied by it's next number
            if(i%4==0){
                // Only if the next number exists
                if(i+1<n){
                    stage2.push_back(stage1[i]*stage1[i+1]);
                    i+=2;
                }
                // If it doesn't exist then just directly push it to stage2 as it is
                else{
                    stage2.push_back(stage1[i]);
                    i++;
                }
            }
            // Directly push it to stage2 as it is
            else{
                stage2.push_back(stage1[i]);
                i++;
            }
        }
        // Then we perform division operation,stage3 will show the condition when we are done with doing division
        vector<int>stage3;
        i=0,n=stage2.size();
        while(i<n){
            // Every 3rd number gets divided by it's next number
            if(i%3==0){
                // Only if it exists
                if(i+1<n){
                    stage3.push_back(stage2[i]/stage2[i+1]);
                    i+=2;
                }
                // If it doesn't exist then just directly push it to stage3 as it is
                else{
                    stage3.push_back(stage2[i]);
                    i++;
                }
            }
            // Directly push it to stage3 as it is
            else{
                stage3.push_back(stage2[i]);
                i++;
            }
        }
        // Now just the addition and subtraction operation are left
        // Sign alternate b/w + and -
        // Using flag to alternate
        int ans=stage3[0],flag=1;
        i=1,n=stage3.size();
        while(i<n){
            if(flag){
                ans+=stage3[i];
            }
            else{
                ans-=stage3[i];
            }
            i++;
            flag^=1;
        }
        // Returning the answer
        return ans;
    }
};
// 2.O(1) Approach
// There is no specific logic for it,it is just based on observation
class Solution {
public:
    int clumsy(int n) {
        if(n==1||n==2){
            return n;
        }
        if(n==3){
            return 6;
        }
        if(n==4){
            return 7;
        }
        if(n%4==0){
            return n+1;
        }
        if(n%4==1||n%4==2){
            return n+2;
        }
        return n-1;
    }
};

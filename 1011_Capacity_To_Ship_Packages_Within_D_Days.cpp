// 1.Brute Force Approach
class Solution {
public:
    bool canShip(int currCap,int days,vector<int>& weights){
        int shippingDays=1;
        int currWeight=0;
        for(int weight:weights){
            if(currWeight+weight>currCap){
                shippingDays++;
                currWeight=0;
            }
            currWeight+=weight;
        }
        return shippingDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // Initialize the size of weights
        int n=weights.size();
        // low and high pointers
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i=0;i<n;i++){
            high+=weights[i];
        }
        // Check every possible capacity
        for(int i=low;i<=high;i++){
            if(canShip(i,days,weights)){
                return i;
            }
        }
        return -1;
    }
};
// 2.Optimal Approach
class Solution {
public:
    bool canShip(int currCap,int days,vector<int>& weights){
        int shippingDays=1;
        int currWeight=0;
        for(int weight:weights){
            if(currWeight+weight>currCap){
                shippingDays++;
                currWeight=0;
            }
            currWeight+=weight;
        }
        return shippingDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // Initialize the size of weights
        int n=weights.size();
        // low and high pointers
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i=0;i<n;i++){
            high+=weights[i];
        }
        while(low<high){
            // Finf mid
            int m=low+(high-low)/2;
            // If we can ship with m days
            // Try lesser value
            if(canShip(m,days,weights)){
                high=m;
            }
            //Otherwise try higher value
            else{
                low=m+1;
            }
        }
        // Answer will be stored in low
        return low;
    }
};

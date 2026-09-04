// 1.Brute Force Approach
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int prod=1;
                for(int k=i;k<=j;k++){
                    prod*=nums[k];
                }
                ans=max(ans,prod);
            }
        }
        return ans;
    }
};
// 2.Better Approach
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int prod=1;
            for(int j=i;j<n;j++){
                prod*=nums[j];
                ans=max(ans,prod);
            }
        }
        return ans;
    }
};
// 3.Optimal Approach 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefixProd=1;
        int suffixProd=1;
        int ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(prefixProd==0){prefixProd=1;}
            if(suffixProd==0){suffixProd=1;}
            prefixProd=prefixProd*nums[i];
            suffixProd=suffixProd*nums[n-i-1];
            ans=max(ans,max(prefixProd,suffixProd));
        }
        return ans;
    }
};

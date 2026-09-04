// 1.Brute Force Approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=0;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        return vector<vector<int>>(st.begin(),st.end());
    }
};
// 2.Optimal Approach
// Sorting then using two pointers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(i>0 && nums[i]==nums[i-1]){continue;}
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){j++;}
                    while(j<k && nums[k]==nums[k+1]){k--;}
                }    
            }
        }
        return ans;
    }
};

// 1.Brute Force Approach
// Time:-O(n⁴)
// 2.Better Approach
// Time:-O(n³) with O(n) space
// 3.Optimal Approach
// Time:-O(n³) with O(1) space
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Answer to return
        vector<vector<int>> ans;
        // Size of nums
        int n=nums.size();
        // Sort nums
        sort(nums.begin(),nums.end());
        // Fix i anf j pointer
        // Then it becomes 2Sum problem
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){continue;}
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]){continue;}
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]){k++;}
                        while(k<l && nums[l]==nums[l+1]){l--;}
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        // Returning the asnwer
        return ans;
    }
};

// 1.Brute Force Approach
// Time:-O(n²)
// Space:-O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Initialize the size of nums and the answer array
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            // To count freq of nums[i] in the array
            int freq=0;
            // Count the freq
            for(int j=0;j<n;j++){
                if(nums[j]==nums[i]){
                    freq++;
                }
            }
            // If freq is greater than n/3
            if(freq>n/3){
                // Check whether this element is already present in the answer or not
                bool alreadyPresent=false;
                for(int j=0;j<ans.size();j++){
                    if(nums[j]==nums[i]){
                        alreadyPresent=true;
                    }
                }
                // If not then add it tot the answer
                if(!alreadyPresent){
                    ans.push_back(nums[i]);
                }
            }
        }
        // Return the answer
        return ans;
    }
};
// 2.Better Approach
// Time:-O(n) on average
// Space:-O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Initialize the size of nums and the answer array
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>freq;
        for(int x:nums){
            freq[x]++;
        }
        for(auto& [x,f]:freq){
            if(f>n/3){
                ans.push_back(x);
            }
        }
        // Return the answer
        return ans;
    }
};
// 3.Optimal Approach
// Time:-O(n) 
// Space:-O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c1=0;
        int c2=0;
        int e1;
        int e2;
        for(int i=0;i<n;i++){
            if(c1==0 && nums[i]!=e2){c1=1;e1=nums[i];}
            else if(c2==0 && nums[i]!=e1){c2=1;e2=nums[i];}
            else if(nums[i]==e1){c1++;}
            else if(nums[i]==e2){c2++;}
            else{c1--;c2--;}
        }
        vector<int> ans;
        int cn1=0;
        int cn2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==e1){
                cn1++;
            }
            else if(nums[i]==e2){
                cn2++;
            }
        }
        int majority= floor(n/3);
        if(cn1>majority){ans.push_back(e1);}
        if(cn2>majority){ans.push_back(e2);}
        return ans;
    }
};

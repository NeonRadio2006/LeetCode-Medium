// 1.Brute Force Approach
class Solution {
public:
    bool possible(int day,int m,int k,vector<int>&bloomDay){
        int ans=0;
        int c=0;
        for(int x:bloomDay){
            if(x<=day){
                c++;
                if(c==k){
                    ans++;
                    c=0;
                }
            }
            else{
                c=0;
            }
        }
        return ans>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // If there aren't enough flowers then we can directly return -1
        if((long long)m*k>(long long)bloomDay.size()){
            return -1;
        }
        // Find low and high pointer
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        // Check for every day
        // As soon as we found a valid day return it
        for(int day=low;day<=high;day++){
            if(possible(day,m,k,bloomDay)){
                return day;
            }
        }
        // Returning -1 if it is not possible
        return -1;
    }
};
// 2.Optimal Approach
class Solution {
public:
    bool possible(int day,int m,int k,vector<int>&bloomDay){
        int ans=0;
        int c=0;
        for(int x:bloomDay){
            if(x<=day){
                c++;
                if(c==k){
                    ans++;
                    c=0;
                }
            }
            else{
                c=0;
            }
        }
        return ans>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // If there aren't enough flowers then we can directly return -1
        if((long long)m*k>(long long)bloomDay.size()){
            return -1;
        }
        // Find low and high pointer
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<high){
            // Find mid
            int mid=low+(high-low)/2;
            // Check for mid
            if(possible(mid,m,k,bloomDay)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        // Final answer will be stored in low
        return low;
    }
};

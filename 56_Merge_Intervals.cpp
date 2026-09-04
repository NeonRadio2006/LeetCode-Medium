class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Initialize the size
        int n = intervals.size();
        // Sort according to start time
        sort(intervals.begin(),intervals.end());  
        // Answer to return
        vector<vector<int>> ans;
        for (int i=0;i<n;i++) {
            // If asnwer is empty OR the last interval's endtime in ans is smaller than our current interval's start time then we ca nnot merge it,so directly push it
            if (ans.empty() || intervals[i][0]>ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            // Otherwise merge our current interval
            else {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]); 
            }
        }
        // Return the answer
        return ans;
    }
};

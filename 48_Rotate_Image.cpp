// 1.Brute Force Approach
// Time:-O(n²)
// Space:-O(n²)
// Observation:-Element initially at position (i,j) goes to (j,n-1-i)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][(n-1)-i]=matrix[i][j];
            }
        }
        matrix=ans;
    }
};
// 2.Optimal Approach
// Time:-O(n²)
// Space:-O(1)
// Observation:- If we first find the transpose of the matrix and then reverse every row of the matrix,we can achieve our answer
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // Finding transpose
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // Reversing every row
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

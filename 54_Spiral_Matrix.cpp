// 1.Brute Force Approach
// Time:-O(m*n)
// Space:-O(m*n)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // m denoted number of rows and n denoted number of columns
        int m=matrix.size();
        int n=matrix[0].size();
        // Boolean visited 2D array
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        // Answer to be returned
        vector<int>ans;
        // Position of current cell
        int currRow=0,currCol=0;
        // Direction in which we are currently moving
        int currDir=0;
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        for(int i=0;i<m*n;i++){
            // Push this cell to the answer
            ans.push_back(matrix[currRow][currCol]);
            // Mark this as true
            visited[currRow][currCol]=true;
            // Go at next cell according to the current direction
            int nextRow=currRow+dr[currDir];
            int nextCol=currCol+dc[currDir];
            // If that cell is invalid that means we have to change our direction
            if(nextRow<0||nextRow>=m||nextCol<0||nextCol>=n||visited[nextRow][nextCol]){
                // Turn 90°
                currDir=(currDir+1)%4;
                nextRow=currRow+dr[currDir];
                nextCol=currCol+dc[currDir];
            }
            // Asiign the new position as current position
            currRow=nextRow;
            currCol=nextCol;
        }
        // Return the answer
        return ans;
    }
};
// 2.Optimal Approach
// Time:-O(m*n)
// Space:-O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;
        vector<int> ans;
        while (top <= bottom && left <= right) {
            // Left -> Right
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;
            // Top -> Bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            // Right -> Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            // Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

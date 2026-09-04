// 1.Brute Force Approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto& row:matrix){
            for(int x:row){
                if(x==target){
                    return true;
                }
            }
        }
        return false;
    }
};
// 2.Optimal Approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Determine the number of rows and columns
        int m=matrix.size();
        int n=matrix[0].size();
        // Target should be within the range of elements of matrix
        if(target<matrix[0][0]||target>matrix[m-1][n-1]){
            return false;
        }
        // Apply BS for every row
        for(int i=0;i<m;i++){
            // Pointer for this row
            int low=0;
            int high=n-1;
            // If target is greater then the last element of this row then just directly move to next row
            if(target>matrix[i][high]){
                continue;
            }
            // If target becomes lesser than any row's first element,then immediately break from the loop
            if(target<matrix[i][0]){
                break;
            }
            // Applying BS for this row
            while(low<=high){
                // Find mid
                int m=low+(high-low)/2;
                // If the target is found then return true
                if(matrix[i][m]==target){
                    return true;
                }
                // If target is greater than the element at mid,then discard left half
                else if(matrix[i][m]<target){
                    low=m+1;
                }
                // Otherwise discard right half
                else{
                    high=m-1;
                }
            }
        }
        // Return false if target does not exists
        return false;
    }
};

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
        // Target should be within the range of elements of the matrix
        if(target<matrix[0][0]||target>matrix[m-1][n-1]){
            return false;
        }
        // Traverse each row
        // Apply BS on each row
        for(int i=0;i<m;i++){
            // Pointers for ith row
            int low=0;
            int high=n-1;
            // If the last element of row is smaller than target that means this row does not contain our target
            if(target>matrix[i][high]){
                continue;
            }
            // Apply BS on this row
            while(low<=high){
                // Find mid
                int m=low+(high-low)/2;
                // Return true if element at mid is the target
                if(matrix[i][m]==target){
                    return true;
                }
                // If target is greater than discard left half
                else if(matrix[i][m]<target){
                    low=m+1;
                }
                // Otherwise fiscard right half
                else{
                    high=m-1;
                }
            }
        }
        // Return false if target is not present
        return false;
    }
};

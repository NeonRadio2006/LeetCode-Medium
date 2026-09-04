// 1.Brute Force Approach
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int up=(i?mat[i-1][j]:-1);
                int right=(j<n-1?mat[i][j+1]:-1);
                int down=(i<m-1?mat[i+1][j]:-1);
                int left=(j?mat[i][j-1]:-1);
                int ele=mat[i][j];
                if(ele>up&&ele>right&&ele>down&&ele>left){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};
// 2.Optimal Approach
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // Determine the number of rows and columns
        int m=mat.size();
        int n=mat[0].size();
        // Pointers for BS on columns
        // Can also do BS in rows
        int l=0;
        int h=n-1;
        while(l<=h){
            // Find mid
            int mid=l+(h-l)/2;
            // Find the row number in this column which has the greatest element
            int r=0;
            for(int i=1;i<m;i++){
                if(mat[i][mid]>mat[r][mid]){
                    r=i;
                }
            }
            // Get that element
            int curr=mat[r][mid];
            // Get it's left and right element
            int left=(mid?mat[r][mid-1]:-1);
            int right=(mid<n-1?mat[r][mid+1]:-1);
            // Check if it is the peak
            if(curr>left&&curr>right){
                return {r,mid};
            }
            // If left is greater then discard right half of the matrix
            if(left>curr){
                h=mid-1;
            }
            // Otherwise discard left half of the matrix
            else{
                l=mid+1;
            }
        }
        // Return {-1,-1} if there is no peak in matrix
        return {-1,-1};
    }
};

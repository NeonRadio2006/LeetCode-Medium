// Time:- O(mn)
// Space:- O(mn)
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        // m denotes the number of rows
        int m=grid.size();
        // n denotes the number of columns
        int n=grid[0].size();
        // Initialize a visited array with all entries as false initially
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        // r and c denotes the our current position
        int r=0,c=0;
        // lastDirection stores the direction we took which made the process end
        char lastDirection;
        // We will move accordingly untill we are within the matrix and not visiting an already visited cell
        while(r>=0&&r<m&&c>=0&&c<n&&!visited[r][c]){
            // Mark the current cell as visited
            visited[r][c]=true;
            // Extract the instructed that we need to follow from th current cell
            char direction=grid[r][c];
            // Moving accordingly
            if(direction=='L'){
                c--;
            }
            else if(direction=='R'){
                c++;
            }
            else if(direction=='U'){
                r--;
            }
            else{
                r++;
            }
            // Storing the latest move at every iteration
            lastDirection=direction;
        }
        // Now we have broken out of the while loop
        // That means we are either outside the matrix or in an already visited cell currently
        // To undo this we just have to move in the opposite direction of the direction we took which made the process end
        // If the last direction we took was left then we have to move one step right
        // If the last direction we took was right then we have to move one step left
        // If the last direction we took was up then we have to move one step down
        // If the last direction we took was down then we have to move one step up
        if(lastDirection=='L'){
            c++;
        }
        else if(lastDirection=='R'){
            c--;
        }
        else if(lastDirection=='U'){
            r++;
        }
        else{
            r--;
        }
        // Return the final answer
        return {r,c};
    }
};

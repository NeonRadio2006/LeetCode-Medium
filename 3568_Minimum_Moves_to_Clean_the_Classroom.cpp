// Given:-mxn grid(rows of strings) and an integer energy
// 'S':-Starting Position,'L':-Litter Position,'R':-Reset Area,'X':-Obstacle Position,'.':-Empty Space
// Once litter is collected,the cell becomes empty
// Reset area restores our energy to full capacity regardless of our current energy.This cell can be used multiple times
// We can not pass through obstacles
// We can move to any valid adjacent cell which will costs 1 energy unit
// If energy reaches 0 then we can only continue if we are in reset area
// Problem Constraints:-m ∈ [1,20],n ∈ [1,20],energy ∈  [1,50],Exactly one 'S' in the grid,At most 10 Litter positions in the grid
// To Do:- minimum number moves to collect all the litter.If not possible then return -1
// We will use bitmask to check whether all litters are collected or not
// As minimum number of moves are asked we would prefer BFS over DFS
// If we reach the same cell with different energy levels then we should prefer the state where energy is more
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        // Initializing the row and column size
        int m=classroom.size();
        int n=classroom[0].size();
        // To determine source row and column
        int sr=0,sc=0;
        // To determine total amount litter present in the classroom
        int totalLitter=0;
        // Assigning unique numbers to each L in the grid
        vector<vector<int>>litters(m,vector<int>(n,-1));
        // Traversing the grid
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // If this cell is the source cell
                if(classroom[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                // If this cell contains litter then assign the totalLitter to this cell and then increment the totalLitter
                if(classroom[i][j]=='L'){
                    litters[i][j]=totalLitter;
                    totalLitter++;
                }
            }
        }
        // If there is no litter in the classroom then we require 0 moves
        if(totalLitter==0){
            return 0;
        }
        // Mask to easily see whether all the litters are collected or not 
        int totMask=(1<<totalLitter)-1;
        // maxEnergy[r][c][mask] will show the highest ever energy we came up with at this cell with this particular mask
        vector<vector<vector<int>>>maxEnergy(m,vector<vector<int>>(n,vector<int>(1<<totalLitter,-1)));
        // Queue for BFS
        // Stores {row,col,energy,mask}
        queue<tuple<int,int,int,int>>q;
        // Push the source with the given energy and no litters collected
        q.push({sr,sc,energy,0});
        // Mark it on the maxEnergy 
        maxEnergy[sr][sc][0]=energy;
        // For Adjacent movement
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        // Final answer
        int totMoves=0;
        while(!q.empty()){
            // Determine the size of the queue currently
            int size=q.size();
            while(size--){
                // Extraact the front
                auto [currRow,currCol,currEnergy,currMask]=q.front();
                // Pop it
                q.pop();
                // If we have collected all the litter then return totMoves
                if(currMask==totMask){
                    return totMoves;
                }
                // If current energy is 0 then this path is useless
                if(currEnergy==0){
                    continue;
                }
                // Going in all 4 directions
                for(int k=0;k<4;k++){
                    // Determining the new row and column
                    int newRow=currRow+dr[k];
                    int newCol=currCol+dc[k];
                    // Checking if movement is possible or not
                    if(newRow>=0&&newRow<m&&newCol>=0&&newCol<n&&classroom[newRow][newCol]!='X'){
                        // Energy decreases by 1
                        int newEnergy=currEnergy-1;
                        int newMask=currMask;
                        // If the new cell is a reset cell then we gain our all energy back
                        if(classroom[newRow][newCol]=='R'){
                            newEnergy=energy;
                        }
                        // If it is a litter cell then collect it
                        if(classroom[newRow][newCol]=='L'){
                            newMask|=(1<<litters[newRow][newCol]);
                        }
                        // If we have higher energy then only push to queue,otherwise not
                        if(maxEnergy[newRow][newCol][newMask]<newEnergy){
                            maxEnergy[newRow][newCol][newMask]=newEnergy;
                            q.push({newRow,newCol,newEnergy,newMask});
                        }
                    }
                }
            }
            // Increment totMoves
            totMoves++;
        }
        // Return -1 if not possible
        return -1;
    }
};

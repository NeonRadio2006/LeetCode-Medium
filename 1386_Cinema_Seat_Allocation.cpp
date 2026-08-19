// 0-Based indexing is done throughout the code for seat number and is not considered for row number as we just need to compare row numbers and not to mark them somewhere
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Initializing the answer with 0
        // Answer would not overflow 'int' as even if there are no reserved seats then answer would be 2*1e9 which also fits in 32-bits that is 'int'
        int ans=0;
        // Sorting the reservedSeats vector for easier processing of rows and calculating the answer effectively
        sort(reservedSeats.begin(),reservedSeats.end());
        // The no of rows in which atleast any one of the seats are reserved
        // This will come in handy afterwards
        int noOfRowsSeen=0;
        // To see which seats are reserved for a particular row
        // If isReserved[i]==1 then this seat is reserved
        // If isReserved[i]==0 then this seat is not reserved
        vector<int>isReserved(10,0);
        // Marking the very first entry
        isReserved[reservedSeats[0][1]-1]=1;
        for(int i=1;i<reservedSeats.size();i++){
            // If current entry is of the same row then just mark the respective seat as reserved
            // 0-Based indexing is not considered here as we are just comparing the rows
            if(reservedSeats[i-1][0]==reservedSeats[i][0]){
                isReserved[reservedSeats[i][1]-1]=1;
            }
            // If we have encountered a new row then:-
            else{
                // First increment the count of rows seen
                // This increment shows that we have no more reserved seats for the (i-1)th row in fututre
                noOfRowsSeen++;
                // First check if all the seats are from 2 to 9 are mepty or not
                // If empty then we can make 2 groups for 4 people that can seated in this row without overlap
                if(!isReserved[1]&&!isReserved[2]&&!isReserved[3]&&!isReserved[4]&&!isReserved[5]&&!isReserved[6]&&!isReserved[7]&&!isReserved[8]){
                    ans+=2;
                }
                // If the seats from 2 to 5 are empty
                else if(!isReserved[1]&&!isReserved[2]&&!isReserved[3]&&!isReserved[4]){
                    ans++;
                }
                // If the seats from 4 to 7 are empty
                else if(!isReserved[3]&&!isReserved[4]&&!isReserved[5]&&!isReserved[6]){
                    ans++;
                }
                // If the seats from 6 to 9 are empty
                else if(!isReserved[5]&&!isReserved[6]&&!isReserved[7]&&!isReserved[8]){
                    ans++;
                }
                // Now set all the values to 0 as we have encountered a new row and now we have to mark reserved seats for this row 
                fill(isReserved.begin(),isReserved.end(),0);
                // Mark the first entry of this row
                isReserved[reservedSeats[i][1]-1]=1;
            }
        }
        // Handling for the last row:-
        // When the loop breaks,the last ongoing row was not calculated as the seen row and also the answer for this row is also not calculated
        // Incrementing the no of seen rows as it was not incremented for the last row
        noOfRowsSeen++;
        // Calculating the answer for last row in the same fashion
        if(!isReserved[1]&&!isReserved[2]&&!isReserved[3]&&!isReserved[4]&&!isReserved[5]&&!isReserved[6]&&!isReserved[7]&&!isReserved[8]){
            ans+=2;
        }
        else if(!isReserved[1]&&!isReserved[2]&&!isReserved[3]&&!isReserved[4]){
            ans++;
        }
        else if(!isReserved[3]&&!isReserved[4]&&!isReserved[5]&&!isReserved[6]){
            ans++;
        }
        else if(!isReserved[5]&&!isReserved[6]&&!isReserved[7]&&!isReserved[8]){
            ans++;
        }
        // Now here we are calculating the no of rows which have no seats reserved in them
        // In these type of row we will could make 2 groups to be seated
        int emptyRows=n-noOfRowsSeen;
        ans+=(2*emptyRows);
        // Returning the answer
        return ans;
    }
};

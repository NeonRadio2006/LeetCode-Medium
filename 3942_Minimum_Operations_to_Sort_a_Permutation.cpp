// Time:- O(n) [is_sorted function and the calculation of ascends and descends along with their indices take O(n) each]
// Space:- O(1) [no extra space created]
class Solution {
public:
    int minOperations(vector<int>& nums) {
        // If the input is already sorted then we require 0 moves
        if(is_sorted(nums.begin(),nums.end())){
            return 0;
        }
        // Determine the size of the input
        int n=nums.size();
        // Handling the case when nums={1,0}
        if(n==2){
            return 1;
        }
        // ascends denote the number of indices i where the element at index i is smaller than the element at index (i+1)
        // ascendIdx denote the index where the element at index (ascendIdx+1) is larger than the element at index ascendIdx
        // descends denote the number of indices i where the element at index i is larger than the element at index (i+1)
        // descendIdx denote the index where the element at index (descendIdx+1) is smaller than the element at index descendIdx
        int ascends=0,descends=0;
        int ascendIdx=-1,descendIdx=-1;
        // We consider wrap around while calculating both the ascend and descend indices along with the numer of ascends and desends
        // We only need maximum of 1 of either one of them, then only we can sort the array
        for(int i=0;i<n;i++){
            // Case when index i is an ascend index
            if(nums[i]<nums[(i+1)%n]){
                ascends++;
                ascendIdx=i;
            }
            // Other wise it will surely be a descend one as all the elements are distinct so there is no "equal to" case
            else{
                descends++;
                descendIdx=i;
            }
        }
        // If the number of ascends are greater than 1 then we can only sort the array when the number of descends is lesser than or equal to 1
        if(ascends>1){
            // Number of descends can't be 0 as even the sorted array also has 1 descend at the index n-1
            // So if the number of descends is 1,then...
            if(descends==1){
                // Currently array is of the form [x+1,x+2,...n-1,0,1,2,...x]
                // Now we also know that nums[descendIdx] is equal to n-1
                // Now we have two options, either sort it just by shifting OR first do a reverse operation and then do shifting
                // If we choose the first option we would have to shift (descendIdx+1) times to sort the whole array
                // Hence, total number of operations is (descendIdx+1)
                // And if we choose the second option and perform reverse operation first which will make the array of the form [x,x-1,...0,n-1,n-2,...x+1]
                // Now we have to see the ascend idex in this reversed array, let that index be j
                // So j = n-descendIdx-1
                // Now if we perform shift operations j times, that will make the array reverse sorted and after that we will perform one more reverse operation to make it sorted
                // Hence, total number of operations required will be j+2 which is  equal to n-descendIdx+1
                // We have to return the minimum of both the options
                return min(descendIdx+1,n-descendIdx+1);
            }
        }
        // If the number of descends are greater than 1 then we can only sort the array when the number of ascends is lesser than or equal to 1
        if(descends>1){
            // Number of ascends can't be 0 as even the reverse sorted array also has 1 ascend at index n-1
            // So if the number of ascends is 1,then...
            if(ascends==1){
                // Currently is of the form [x,x-1,...0,n-1,n-2,...x+1]
                // Now we also know that nums[ascendIdx] is equal to 0
                // Now here also we have two options, either first perform shift operations and then reverse OR first perform a reverse operation and then shift ones
                // Now if we choose the first option we have to shift (ascendIdx+1) times to make the array reverse sorted and one extra reverse operation ot finally make the array sorted
                // Hence, total number of operations is (ascendIdx+2)
                // And if we choos the second option and perform a reverse operation first which wil make the array of the form [x+1,x+2,...n-1,0,1,2,...x]
                // Now we have to see th descend index in this reversed array, let that index be i
                // So i=n-ascendIdx-1
                // Now if we perform shift operations (i+1) times, that will make the array sorted
                // Hence, total number of operations required will be n-ascendIdx
                // We have to return the minimum of both the options
                return min(ascendIdx+2,n-ascendIdx);
            }
        }
        // If none of the cases are satisfied then it is impossible to sort the array 
        // Hence returning -1 for the impossible case
        return -1;
    }
};

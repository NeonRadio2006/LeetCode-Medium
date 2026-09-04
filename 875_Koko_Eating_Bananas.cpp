// 1.Brute Force Approach
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Max value of k can be 1e9
        int mx=*max_element(piles.begin(),piles.end());
        // Trying every k
        for(int k=1;k<=mx;k++){
            // Calculate the hours in which koko will eat all bananas wrt k
            long long hrs=0;
            for(int pile:piles){
                hrs+=(pile+k-1)/k;
            }
            // If this is lesser than h then return this k immediately
            if(hrs<=h){
                return k;
            }
        }
        return -1;
    }
};
// 2.Optimal Approach
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Initialize the size of piles
        int n=piles.size();
        int low=1;
        // High will be the max element of the piles
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            // Find mid
            int mid=low + (high-low)/2;
            // Find total hours that koko will take to eat all bananas wrt this mid
            long long hourstoeat=0;
            for(int i=0;i<n;i++){
                hourstoeat+=ceil((double)piles[i] / (double)mid);
            }
            // If the calculated total hours are lesser than h then we have found a candidate
            // Try to search for more smaller k
            if(hourstoeat<=h){
                high=mid-1;
            }
            // Try for greater k
            else{
                low=mid+1;
            }
        }
        // Final answer will be stored at low
        return low;
    }
};

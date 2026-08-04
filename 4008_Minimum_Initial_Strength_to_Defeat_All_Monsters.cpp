class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        // Initializing the size of monsters ans boosts arrays
        int n=monsters.size(),m=boosts.size();
        // If there are no boosts then we need the strength equal to the sum of strengths of all monsters
        if(m==0){
            long long ans=0;
            for(int i=0;i<n;i++){
                ans+=monsters[i];
            }
            return ans;
        }
        // Calculating the fianl boost at a particular index after every boosts is applied
        vector<long long>finalBoostAt(n,0);
        // To calculate the final boost at an index,we will use Difference Array Technique,which will make processing of each query a O(1)
        for(auto& boost:boosts){
            int l=boost[0];
            int r=boost[1];
            long long v=boost[2];
            finalBoostAt[l]+=v;
            if(r+1<n){
                finalBoostAt[r+1]-=v;
            }
        }
        // Do prefix sum to get the final boost at an index
        for(int i=1;i<n;i++){
            finalBoostAt[i]+=finalBoostAt[i-1];
        }
        // For an index i,currAns means the strength must be remaining after defeating the ith monster and prevAns means the strength remaining after defeating the (i+1)th monster
        // Now to find the minum strength we will traverse backwards from index n-2
        // Why from n-2?
        // Because we can always consider that the fianl remaining strength after the last monster is 0.This is done to minimmize the final answer.Hence prevAns is initialized with 0
        // We are doing it till -1 bcz to get the final answer we need to find currAns by taking answer at 0th index as prevAns
        long long prevAns=0,currAns;
        for(int i=n-2;i>=-1;i--){
            // If the prevAns is not 0 then we need currAns as prevAns+strength of the (i+1)th monster
            // Why?
            // In this case boost doesn't matter bcz prevAns+strength of the (i+1)th monster is always greater than or equal to strength of the (i+1)th monster
            if(prevAns!=0){
                currAns=prevAns+monsters[i+1];
            }
            // If the prevAns is 0
            else{
                // First we need to know what are the boost and strength at (i+1)th index
                long long nextBoost=finalBoostAt[i+1];
                int nextMonster=monsters[i+1];
                // If the boost is greter than or equal to the strength then the currAns can be 0
                // Bcz on arriving on the index (i+1) with strength as 0 we will gain enough boost to defeat the monster and then afterwards are strength will become negative,but acc to the question when this happens strength automatically restores to 0
                if(nextBoost>=nextMonster){
                    currAns=0;
                }
                // And if the boost is smaller than the strength,then we can assign currAns as the difference between the strength and the boost
                // We will gain boost and then we will be able to defeat that monster and then our strength will become negative but the it will automatically restore to 0
                else{
                    currAns=nextMonster-nextBoost;
                }
            }
            // Assign currAns as prevAns for next iteration
            prevAns=currAns;
        }
        // Returning prevAns because it stores the final asnwer when the iteration of i==-1 happens
        return prevAns;
    }
};

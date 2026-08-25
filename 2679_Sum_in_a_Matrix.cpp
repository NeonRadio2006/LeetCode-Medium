class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n=nums.size();
        // Vector of priority queue to easily get the current largest element in that row
        vector<priority_queue<int>>sortedList(n);
        // Precomputation step
        for(int i=0;i<n;i++){
            for(int x:nums[i]){
                sortedList[i].push(x);
            }
        }
        // Initialize the answer
        int ans=0;
        while(true){
            // Initialize the mx with -1 so that if all the priority queues are empty then we can easily break out from the loop
            int mx=-1;
            for(int i=0;i<n;i++){
                if(!sortedList[i].empty()){
                    // Find the max number
                    mx=max(mx,sortedList[i].top());
                    // Remove the elemnt from the queue
                    sortedList[i].pop();
                }
            }
            // If every priority queue is empty then break from the while loop
            if(mx==-1){
                break;
            }
            // Add this mx to the answer
            ans+=mx;
        }
        // Returning the answer
        return ans;
    }
};

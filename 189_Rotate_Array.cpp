// 1.Brute Force
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Initialize the size
        int n=nums.size();
        // Take modulo of k wrt n as if k>n then we will repeat arrays again and again
        k%=n;
        // Take out the last element
        // Shift all rest of the elements to right by one position
        // Assign the removed number at the 0th index
        // Do this k times
        while(k--){
            int last=nums[n-1];
            for(int i=n-1;i>0;i--){
                nums[i]=nums[i-1];
            }
            nums[0]=last;
        }
    }
};
// 2.Optimal Approach 1
class Solution {
public:
    // Funtion to reverse
    void reverse(vector<int> &nums,int start,int end){
        while(start<=end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
    // This is based on observation
    void rotate(vector<int>& nums, int k) {
        // Initialize the size
       int n=nums.size();
       // Take modulo of k wrt n as if k>n then we will repeat arrays again and again
       k=k%n;
       // Reverse first n-k elements
       reverse(nums,0,n-k-1);
       // Reverse the last k elements
       reverse(nums,n-k,n-1);
       // Reverse the whole array
       reverse(nums,0,n-1);
    }
};
// 3.Optimal Approach 2
// This is known as juggling algo(Optional)
// If you note down which element moved to which index in the final answer while doing the dry run for some cases
// You will notice that indices form cycle(s)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Initialize the size
        int n=nums.size();
        // Take modulo of k wrt n as if k>n then we will repeat arrays again and again
        k=k%n;
        // Find total number of cycles
        int noOfCycles=gcd(n,k);
        // For every cycle
        for(int i=0;i<noOfCycles; i++){
            int curr=i;
            int prev=nums[i];
            while(true){
                int next=(curr+k)%n;
                swap(prev,nums[next]);
                curr=next;
                if(curr==i){
                    break;
                }
            }
        }
    }
};

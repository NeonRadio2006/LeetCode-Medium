// 1.Brute Force
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // Initialize the size of nums
        int n=nums.size();
        // Traverse through the array
        // We will try to find smallest element we can place in that index according to the given limit condition
        // Finding a smaller element bcz if we swap it with a larger one than it will not be lexicographically smaller
        for(int i=0;i<n;i++){
            // Traverse the rest of the array again and again untill we can't find a smaller element to replace to
            while(true){
                // This variablle will be used to find smallest element at the right of the ith element
                int elementToSwap=nums[i];
                // Storing the index so that we can replace
                int idx=-1;
                // Finding a smaller element on the right side from which absolute difference is lesser than equal to limit
                for(int j=i+1;j<n;j++){
                    if(abs(nums[i]-nums[j])<=limit){
                        if(nums[j]<elementToSwap){
                            elementToSwap=nums[j];
                            idx=j;
                        }
                    }
                }
                // If idx is not -1 that means we have found an element from which we can swap
                if(idx!=-1){
                    swap(nums[i],nums[idx]);
                }
                // And if idx is still -1,that means we haven't found any valid element to swap
                // Hence break from the while loop
                else{
                    break;
                }
            }
        }
        // Returning the answer
        return nums;
    }
};
// 2.Optimal Approach
// We can make clusters of elements which can be swapped.For Ex:- if nums[i] and nums[j] can be swapped and nums[j] and nums[j] can be swapped with nums[k]
// Then we can make a cluster of nums[i],nums[j],nums[k]
// No element will ever be present in more than 1 clusters.There can be a clusters of size 1
// For a cluster we can produce all permutations of that cluster.So we will prefer the sorted order to produce lexicographically smallest answer
// Now how to form those clusters?
// Observe that if the elements of a cluster are sorted then the difference between every pair of adjacent elements will always be lesser than or equal to limit
// So we will sort the input array and we will traverse till difference between adjacent elements are lesser than or equal to limit and these elements will form a cluster
// While traversing if difference is greater than limit,that means we have to start a new cluster
// We can use a map to make a cluster or 2D vector also
// Now how do we merge these clusters?
// We can't just directly merge all the clusters
// We will traverse the original array and see the cluster from which this element belongs to,and then see the smallest unused element in that cluster
// Place that element and then move to next element in our original array
// Now how to find which cluster does this element belong to?
// We can use map for this 
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // Initializing the size of nums
        int n=nums.size();
        // Making a seperate array for sorted nums
        // Not sorting the actual array as we will need it afterwards to find the final answer
        vector<int>sortedNums=nums;
        sort(sortedNums.begin(),sortedNums.end());
        // This will store the elements which are in ith cluster
        // cluster[i] will be sorted as we will traverse over sortedNums
        vector<vector<int>>cluster;
        // This maps the element to it's respective cluster
        unordered_map<int,int>elementToCluster;
        // This will come in handy when we are finding the final answer
        // smallestPos[i] shows the position of smallest element in cluster[i] that is not placed
        vector<int>smallestPos;
        // Precomputation Step
        for(int x:sortedNums){
            // If prev element does not satisfy the condition then add a new cluster
            if(cluster.empty()||x-cluster.back().back()>limit){
                // Adding a new cluster
                cluster.push_back({});
                // Initializing with 0 for every cluster[i] as all cluster[i] will be sorted and the smallest element will be the element at 0th position
                smallestPos.push_back(0);
            }
            // Add the element in the last cluster[i] that cluster has
            cluster.back().push_back(x);
            // Also map the element
            // Don't forget the -1
            elementToCluster[x]=cluster.size()-1;
        }
        // Traversing the original nums to find the final answer
        for(int i=0;i<n;i++){
            // First find the cluster of this element
            int respCluster=elementToCluster[nums[i]];
            // Find the smallest unplaced/unused element of this cluster
            // Here we don't need to check whether respCluster is a valid index or not as there is no overlap between any two clusters
            int currSmallest=cluster[respCluster][smallestPos[respCluster]];
            // Increment the pointer for this cluster
            smallestPos[respCluster]++;
            // Assign this element to the ith position
            nums[i]=currSmallest;
        }
        // Returning the final answer
        return nums;
    }
};

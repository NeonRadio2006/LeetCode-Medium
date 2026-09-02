class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // Find the minimum element
        int minele=*min_element(nums1.begin(),nums1.end());
        // If the minimum element is odd then we can make nums2 all odd
        // If and element is odd then we will directly keep it
        // And if it is even then we can subtract the minimum element to make it odd
        if(minele%2){
            return true;
        }
        // If minimum element is not odd:-
        // Then every element in nums1 should be even.Why?
        // Bcz let's say we want to make every element odd but the minimum one is even and we need an smaller odd to subtract from it but there is not a smaller element hence not possible
        // Let's say we want to make every element even and we have odds at some positions.we need to subtract a smaller odd from a odd number to make it even but the smallest don't have one
        // Hence if minimum element is even and there exists a odd in nums1 then it is impossible to do so
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2){
                return false;
            }
        }
        return true;
    }
};

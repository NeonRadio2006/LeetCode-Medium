class Solution {
public:
    // It is a standard stars and bars approach
    // We have to calculate the ways such that x+y+z=n,where x,y,z>limit
    // Imagine through venn diagram
    // First we will calculate the total number of ways to distribute n candies among 3 children such that any child can get any amount of candies(including 0)
    // Hence total will be ⁿ⁺²∁₂
    // n(x ∪ y ∪ z)=n(x)+n(y)+n(z)-(n(a ∩ b)+n(b ∩ c)+n(a ∩ c))+n(a ∩ b ∩ c)
    // Case-1:-Calculating the cases where exactly one child gets more than limit candies:-
    // RHS will become n-(limit+1),then apply stars and bars on that equation,which will become (n-limit+1)C2 and there 3 possibility of this case hence 3*(n-limit+1)C2
    // This will be n(x)+n(y)+n(z)
    // Case-2:-Calculating the cases where exactly two children gets more than limit candies:-
    // RHS will become n-2*(limit+1),then apply stars and bars on that equation,which will become (n-2*limit)C2 and there 3 possibility of this case hence 3*(n-2*limit)C2
    // This will be n(a ∩ b)+n(b ∩ c)+n(a ∩ c)
    // Case-3:-Calculating the case where all three children got more than limit candies:-
    // RHS will become n-3*(limit+1),then apply stars and bars on that equation,which will become (n-3*limit-1)C2 and there is only 1 possibility of this case hence (n-2*limit)C2
    // This will be n(a ∩ b ∩ c)
    // Now for calculating nC2 we can just do n*(n-1)/2,if and only if n>=2
    long long nC2(long long n){
        if(n<2){
            return 0;
        }
        return n*(n-1)/2;
    }
    long long distributeCandies(int n, int limit) {
        long long total=nC2(n+2);
        long long xUyUz=(3*nC2((long long)n-1LL*limit+1))-(3*nC2((long long)n-2LL*limit))+(nC2((long long)n-3LL*limit-1));
        long long complement=total-xUyUz;
        return complement;
    }
};

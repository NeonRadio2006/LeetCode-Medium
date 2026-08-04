// Got this approach after many trials
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        // Initializing the answer we need to return
        vector<int>ans;
        // A boolean vector to check if we have used a particular number in our answer
        vector<bool>used(n+1,false);
        // Start constructing our answer from 1
        ans.push_back(1);
        // Mark 1 as used
        used[1]=true;
        // The main logic is that as we need exactly k different differences and not exactly k differences which means that the differences can repeat
        // The first thought of k distinct differences are 1,2,3,...k. In this problem we will first construct difference of k then k-1 then k-2 and so on till 1
        while(k>0){
            // It is a number which will be pushed next our answer
            int numToBePushed;
            // There are two candidates with current difference k either k more than the last element of the current answer array or k less than the last element of the current  answer array
            int candidate1=ans.back()+k;
            int candidate2=ans.back()-k;
            // 1.We first need to make sure that the number which is k more than the last element is lesser than n or not
            // 2.We also need make sure that this element is not used,then only we can add this element to our answer
            // 3.The condition that the element is lesser than n or not need to be checked first because if the 2nd condition is checked first and if the candidate is greater than n,then code will give out of bound error
            if(candidate1>n||used[candidate1]){
                numToBePushed=candidate2;
            }
            // 1.We first need to make sure that the number which is k less than the last element is greater than 0 or not
            // 2.We also need make sure that this element is not used,then only we can add this element to our answer
            // 3.The condition that the element is greater than 0 or not need to be checked first because if the 2nd condition is checked first and if the candidate is lesser than 0,then code will give out of bound error
            else if(candidate2<=0||used[candidate2]){
                numToBePushed=candidate1;
            }
            // 1.If both elements are within the bounds and also not used,then pick the candidate which is smaller
            // I do not have an exact proof why to choose the smaller candidate.but one way to understand is that if we choose the greater one then in future the smaller one will be next to more larger element which introduces a new difference
            else if(!used[candidate1]&&!used[candidate2]){
                numToBePushed=min(candidate1,candidate2);
            }
            // This most probably never executes,we can also ignore this
            else{
                continue;
            }
            // Now the number that is to be psuhed is noe decided,so push it in the answer
            ans.push_back(numToBePushed);
            // Mark this number as used
            used[numToBePushed]=true;
            // Decrement the k
            k--;
        }
        // Now some numbers from 1 to n might have not been used,this depends on the value of k
        // So we can just add them in increasing order and it does not produce a new difference
        for(int i=1;i<=n;i++){
            if(!used[i]){
                ans.push_back(i);
            }
        }
        // Return the asnwer
        return ans;
    }
};

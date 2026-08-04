// 1.Pure Recursive approach
class Solution {
public:
    //DFS
    void dfs(int i,int currCost,int target,int& ans,vector<int>& toppingCosts){
        //If we have found a closer sum OR we have found the sum which is equally closer AND is smaller one
        if(abs(currCost-target)<abs(ans-target)||((abs(currCost-target)==abs(ans-target)&&currCost<ans))){
            ans=currCost;
        }
        // All the toppings are considered
        if(i==toppingCosts.size()){
            return;
        }
        // Take 0 copies of this topping
        dfs(i+1,currCost,target,ans,toppingCosts);
        // Take 1 copy of this topping
        dfs(i+1,currCost+toppingCosts[i],target,ans,toppingCosts);
        // Take 2 copies of this topping
        dfs(i+1,currCost+2*toppingCosts[i],target,ans,toppingCosts);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        // Initialize the answer with maximum
        int ans=INT_MAX;
        // Trying each base cost
        for(int baseCost:baseCosts){
            dfs(0,baseCost,target,ans,toppingCosts);
        }
        // Returning the answer
        return ans;
    }
};

// 2.Pure Recursive approach with pruning
class Solution {
public:
    //DFS
    void dfs(int i,int currCost,int target,int& ans,vector<int>& toppingCosts){
        //If we have found a closer sum OR we have found the sum which is equally closer AND is smaller one
        if(abs(currCost-target)<abs(ans-target)||((abs(currCost-target)==abs(ans-target)&&currCost<ans))){
            ans=currCost;
        }
        // All the toppings are considered
        if(i==toppingCosts.size()){
            return;
        }
        // Measure to reduce the size of the recursion tree
        if(currCost>=target){
            return;
        }
        // Take 0 copies of this topping
        dfs(i+1,currCost,target,ans,toppingCosts);
        // Take 1 copy of this topping
        dfs(i+1,currCost+toppingCosts[i],target,ans,toppingCosts);
        // Take 2 copies of this topping
        dfs(i+1,currCost+2*toppingCosts[i],target,ans,toppingCosts);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        // Initialize the answer with maximum
        int ans=INT_MAX;
        // Trying each base cost
        for(int baseCost:baseCosts){
            dfs(0,baseCost,target,ans,toppingCosts);
        }
        // Returning the answer
        return ans;
    }
};

// 3.Pure Recursive approach with pruning and sorting
class Solution {
public:
    //DFS
    void dfs(int i,int currCost,int target,int& ans,vector<int>& toppingCosts){
        //If we have found a closer sum OR we have found the sum which is equally closer AND is smaller one
        if(abs(currCost-target)<abs(ans-target)||((abs(currCost-target)==abs(ans-target)&&currCost<ans))){
            ans=currCost;
        }
        // All the toppings are considered
        if(i==toppingCosts.size()){
            return;
        }
        // Measure to reduce the size of the recursion tree
        if(currCost>=target){
            return;
        }
        // Take 0 copies of this topping
        dfs(i+1,currCost,target,ans,toppingCosts);
        // Take 1 copy of this topping
        dfs(i+1,currCost+toppingCosts[i],target,ans,toppingCosts);
        // Take 2 copies of this topping
        dfs(i+1,currCost+2*toppingCosts[i],target,ans,toppingCosts);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        // Initialize the answer with maximum
        int ans=INT_MAX;
        // Sorting the toppings array in descending order so that the pruning statement hits more earlier
        sort(toppingCosts.rbegin(),toppingCosts.rend());
        // Trying each base cost
        for(int baseCost:baseCosts){
            dfs(0,baseCost,target,ans,toppingCosts);
        }
        // Returning the answer
        return ans;
    }
};

// 1.Solution using extra space
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // In this we will store indices of critical points
        vector<int>indices;
        // Index of current pointer
        int currIdx=1;
        // Two pointers for one time traversal
        ListNode* prev=head;
        ListNode* curr=head->next;
        // Traverse till next node of curr node exists
        while(curr->next){
            // Condition for local minima
            if(curr->val<min(prev->val,curr->next->val)){
                indices.push_back(currIdx);
            }
            // Condition for local maxima
            if(curr->val>max(prev->val,curr->next->val)){
                indices.push_back(currIdx);
            }
            // Increment the index of curr pointer
            currIdx++;
            // Shift both the pointers one node ahead
            prev=curr;
            curr=curr->next;
        }
        // If list have have no more than 1 critical points then return {-1,-1}
        if(indices.empty()||indices.size()==1){
            return {-1,-1};
        }
        // Max distance will be between first and last critical points
        int mx=indices[indices.size()-1]-indices[0];
        int mn=1e9;
        // Finding minimum dist between critical points
        // As the indices are sorted then minimum dist would be between two adjacent ones only
        for(int i=0;i<indices.size()-1;i++){
            mn=min(mn,indices[i+1]-indices[i]);
        }
        // Returning the answer
        return {mn,mx};
    }
};
// 2.Constant Space Solution
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Index of current pointer
        int currIdx=1;
        // Two pointers for one time traversal
        ListNode* prev=head;
        ListNode* curr=head->next;
        // Denotes index of first critical point
        int firstCritical=-1;
        // Denotes index of last critical point
        int lastCritical=-1;
        // Denotes the minimum distance between any two nodes
        int mn=1e9;
        // Traverse till next node of curr node exists
        while(curr->next){
            bool isACriticalNode=false;
            // Condition for local minima
            if(curr->val<min(prev->val,curr->next->val)){
                isACriticalNode=true;
            }
            // Condition for local maxima
            if(curr->val>max(prev->val,curr->next->val)){
                isACriticalNode=true;
            }
            if(isACriticalNode){
                // If this is the first critical node
                if(firstCritical==-1){
                    firstCritical=currIdx;
                }
                // If not then update the minimum distance
                else{
                    mn=min(mn,currIdx-lastCritical);
                }
                // Assign this index as the index of the last seen critical node
                lastCritical=currIdx;
            }
            // Increment the index of curr pointer
            currIdx++;
            // Shift both the pointers one node ahead
            prev=curr;
            curr=curr->next;
        }
        // If list have have no more than 1 critical points then return {-1,-1}
        if(firstCritical==-1||firstCritical==lastCritical){
            return {-1,-1};
        }
        // Max distance will be between first and last critical points
        int mx=lastCritical-firstCritical;
        // Returning the answer
        return {mn,mx};
    }
};

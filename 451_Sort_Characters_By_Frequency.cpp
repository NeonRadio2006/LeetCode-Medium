class Solution {
public:
    string frequencySort(string s) {
        // Unordered map to store frequenciey of every character
        unordered_map<char,int>freq;
        for(char c:s){ 
            freq[c]++;
        }
        // Priority queue storing pair of character and it's frequency
        priority_queue<pair<int,char>> pq;
        for(auto &p : freq) {
            pq.push({p.second, p.first});
        }
        // Initialize empty answer
        string res = "";
        // Now go through the priority queue
        while(!pq.empty()){
            // Get the top pair
            auto [f,c]=pq.top();
            // Pop it from the priority queue
            pq.pop();
            // Apped that character f times
            for(int i=0;i<f;i++){
                res+=c;
            }
        }
        return res;
    }
};

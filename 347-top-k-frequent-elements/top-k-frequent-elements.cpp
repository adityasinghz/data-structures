class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int>res;
        for(auto a : nums){
            mp[a]++;
        }

        for(auto m : mp){
            q.push({m.second,m.first});
            if(q.size() > k) q.pop();
        }
        
        while (!q.empty()) {
        res.push_back(q.top().second);
        q.pop();
        } 
        return res;
    }
};
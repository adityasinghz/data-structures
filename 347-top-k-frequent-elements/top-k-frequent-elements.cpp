class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>res;
        for(auto num : nums){
            freq[num]++;
        }

        for(auto f : freq){
            pq.push({f.second,f.first});
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
             res.push_back(pq.top().second);
             pq.pop();
        }
        return res;
    }
};
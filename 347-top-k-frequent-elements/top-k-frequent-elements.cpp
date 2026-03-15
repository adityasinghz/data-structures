class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int>freq;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      for(auto num : nums){
        freq[num]++;
      }

      for(auto m : freq){
        pq.push(make_pair(m.second, m.first));
        if(pq.size() > k) pq.pop();
      }
      vector<int>ans;
      while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
      }
      return ans;
    }
};
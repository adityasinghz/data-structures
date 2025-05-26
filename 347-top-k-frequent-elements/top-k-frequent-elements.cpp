class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int>mp;
         vector<int>ans;
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
         }
         
         for(auto m : mp){
            pq.push({m.second,m.first});
            if(pq.size()>k)pq.pop();
         }
         while(!pq.empty()){
              ans.push_back(pq.top().second);
              pq.pop();
         }
         return ans;
    }
};
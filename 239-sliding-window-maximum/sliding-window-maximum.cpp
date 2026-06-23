class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        vector<int>res;
        priority_queue<pair<int,int>>pq;
        while( j  <  n ){
           pq.push(make_pair(nums[j], j));
           if(j - i  + 1 == k){
              res.push_back(pq.top().first);
              i++;
           }
           while(!pq.empty() && pq.top().second < i){
             cout<<pq.top().first<<' '<<pq.top().second<<' '<<i<<'\n';
             pq.pop();
           }
           j++;
        }
        return res;
    }
};
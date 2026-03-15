class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>bucket(n+1);
        unordered_map<int,int>freq;
        vector<int>ans;
        for(int num : nums){
            freq[num]++;
        }
        
        for(auto p : freq){
            bucket[p.second].push_back(p.first);
        }
        
        for(int i=n;i>=0;i--){
            for(auto b : bucket[i]){
             ans.push_back(b);
             if(ans.size() == k) return ans;
            }
        }
        return {};
    }
};
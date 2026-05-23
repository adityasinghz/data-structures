class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>buckets(n+1);
        unordered_map<int,int>freq;
        vector<int>ans;
        for(int num : nums){
            freq[num]++;
        }

        for(auto f : freq){
            buckets[f.second].push_back(f.first);
        }

        for(int i = n; i>=0; i--){
            for(auto num : buckets[i]){
                ans.push_back(num);
                if(ans.size() == k) return ans;
            }
        }
        return {};
    }
};
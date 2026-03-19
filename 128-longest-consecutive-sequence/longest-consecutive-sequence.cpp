class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans = 0;
        for(auto num : st){
            int curr = num;
            int stre = 1;
            if(!st.count(curr-1)){
                while(st.count(curr+1)){
                     curr++;
                     stre++;
                }
            }
            ans = max(ans, stre);
        }
        return ans;
    }
};
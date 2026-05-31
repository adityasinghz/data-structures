class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int res = 0;
        for(int num : st){
             int ct = 1;
             int nu = num;
             if(st.count(num-1)) continue;

             while(st.count(nu+1)){
                 nu++;
                 ct++;
             }
             res = max(ct,res);
        }
        return res;
    }
};
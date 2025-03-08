class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        for(auto num : nums){
            st.insert(num);
        }
        int prev = 0;
        int count = 0;
        int maxi = 0;
        for(auto it : st){
             if(it -  prev == 1) count++;
             else{
              count=1;
             }
             maxi = max(maxi, count);
             prev = it;
        }
        return maxi;
    }
};
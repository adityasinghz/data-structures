class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>setArr(nums.begin(),nums.end());
        int ans = 0;
        for(auto num : setArr){
             int curr = num;
             int streak = 1;
             if(!setArr.count(num-1)){
                   while(setArr.count(curr+1)){
                    curr++;
                    streak++;
                   }
             }
             ans = max(ans, streak);
        }
        return ans;
    }
};
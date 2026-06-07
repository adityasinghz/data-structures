class Solution {
public:
    int lengthOfLongestSubstring(string s) { // abba
        int i = 0;
        int j = 0;
        int n = s.size();
        unordered_map<int,int>mp;
        int ans = 0;
        while( j < n ){
             if(mp.count(s[j]) && mp[s[j]] >= i) i = mp[s[j]]+1;
             ans = max(ans, j - i + 1);
             mp[s[j]] = j;
             j++;
        }
        return ans;
    }
};
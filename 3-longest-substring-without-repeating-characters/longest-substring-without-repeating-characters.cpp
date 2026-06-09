class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxLen = 0;
        unordered_map<int,int>mp;
        while( j < n ){
            while(mp[s[j]]){mp[s[i]] = false; i++;}
            maxLen = max(maxLen, j - i + 1);
            mp[s[j]] = true;
            j++;
        }
        return maxLen;
    }
};
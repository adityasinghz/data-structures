class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        unordered_map<char,int>freq;
        int maxLen = 0;
        while( j < n){
           if(freq.find(s[j]) != freq.end() && i <= freq[s[j]]){
              i = freq[s[j]] + 1;
           }
           maxLen = max(maxLen, j - i  + 1);
           freq[s[j]] = j;
           j++;
        }
        return maxLen;
    }
};
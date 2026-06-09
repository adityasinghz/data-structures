class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;

        for(int i=0; i < n; i++){
            unordered_map<char,int>freq;
            int j = i;
            for(; j < n; j++){
                if(freq[s[j]]) break;
                freq[s[j]] = true;
            }
            maxLen = max(maxLen,  j - i);
        } 
        return maxLen;
    }
};
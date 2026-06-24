class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>freq;

        int j = 0;
        int i = 0;
        int n = s.size();
        int maxLen = 0;
        while( j < n){
            if(freq.find(s[j]) != freq.end() && i <= freq[s[j]])  i = freq[s[j]] + 1;
            cout<<" j "<<j<<' '<<" i "<<i<<'\n';
            maxLen = max(maxLen, j - i + 1);
            freq[s[j]] = j;
            j++;
        }
        return maxLen;
    }
};
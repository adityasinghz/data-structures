class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans = 0;
        unordered_map<char,int>freq;
        while( j < n){
            if(freq.count(s[j]) > 0 && i <= freq[s[j]]){
                i = freq[s[j]]+1;
            }
            freq[s[j]] = j;
            cout<<s[j]<<j<<' '<<i<<' '<<(j-i+1)<<'\n';
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
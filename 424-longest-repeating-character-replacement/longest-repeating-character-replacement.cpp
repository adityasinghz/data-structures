class Solution {
public:
    int characterReplacement(string s, int k) {
        int j = 0;
        int i = 0;
        int n = s.size();
        int maxLen= 0;
        vector<int>freq(26,0);
        while( j < n ){
            freq[s[j] - 'A']++;
            int maxFreq = 0;

            for(auto f : freq)
               maxFreq = max(f, maxFreq);

            while( ( j - i + 1 - maxFreq ) > k ){
                 freq[s[i] - 'A']--;
                 i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;

    }
};
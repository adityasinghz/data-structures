class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxFreq  = 0;
        int maxLen = 0;
        int i = 0;
        int j = 0;
        unordered_map<char,int>freq;
        while( j < n ){
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);
            int rem =  j - i + 1 - maxFreq;

            while(rem > k){ 
                freq[s[i]]--;
                int tempMaxFreq = 0;
                for(auto m : freq) tempMaxFreq = max(tempMaxFreq, m.second);
                i++;
                rem =  j - i + 1 - tempMaxFreq; 
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};
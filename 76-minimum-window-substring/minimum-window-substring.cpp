class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;

        for (auto c : t)
            freq[c]++;

        int j = 0;
        int i = 0;
        int n = s.size();
        int m = t.size();
        int ct = 0;
        int initialI = -1;
        int minLen = INT_MAX;
        while (j < n) {
            if (freq[s[j]] > 0) {
                ct++;
            }
            freq[s[j]]--;
            if (ct == m) {
                
                do {
                    if (j - i + 1 < minLen) {
                    minLen = min(minLen, j - i + 1);
                    initialI = i;
                    }
                    if (freq[s[i]] == 0) ct--;
                    
                    ++freq[s[i]];
                    i++;
                    
                } while (ct == m);
                
            }

            j++;
        }
        return initialI > -1 ? s.substr(initialI, minLen) : "";
    }
};
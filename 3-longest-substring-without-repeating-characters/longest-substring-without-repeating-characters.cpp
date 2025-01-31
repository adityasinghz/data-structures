class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(256,-1);
        int i = -1;
        int j = 0;
        int maxi = 0;
        while(j < s.size()){
            if(freq[s[j]] > i){
                i=freq[s[j]];
            }
            freq[s[j]] = j;
            maxi = max(maxi, j-i);
            j++;
        }
        return maxi;
    }
};
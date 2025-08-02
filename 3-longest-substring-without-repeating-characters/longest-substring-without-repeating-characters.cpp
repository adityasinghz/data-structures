class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int len = s.size();
         vector<int>lastSeen(256,-1);
         int i = -1;
         int j =  0;
         int maxi = 0;
         while( j < len){
            if(lastSeen[s[j]] > i){
                i = lastSeen[s[j]];
            }
            lastSeen[s[j]] = j;
            maxi = max(maxi, j - i);
            j++;
         }
        return maxi;
    }
};
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxi = 0;

        while( j < n ){
            while(mp[s[j]]==2){
                mp[s[i]]--;
                i++;
            }
            maxi = max(maxi, j - i + 1);
            mp[s[j]]++;
            j++;
        }
        return maxi;
    }
};
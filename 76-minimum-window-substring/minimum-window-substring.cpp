class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t) return s;
        int i = 0;
        int j = 0;
        int m = s.size();
        int n = t.size();
        if ( n == 0 || m == 0 || n > m) return "";
        int ct = 0;
        int minL = INT_MAX;
        int minI = -1;
        int minJ = -1;
        unordered_map<char,int>mp;
        for(auto c : t) mp[c]++;
        while( j < m){
            if(mp[s[j]] > 0){
                ct++;
            }
            while( i <= j && ct==n){
                if(minL > j - i + 1){
                   minI = i;
                   minJ = j;
                   minL = j - i + 1;
                }
                cout<<i<<' '<<j<<'\n';
                if(mp[s[i]] >= 0) ct--;
                mp[s[i]]++;
                i++;
            }
            mp[s[j]]--;
            j++;
        } 
        return minL==INT_MAX ? "" : s.substr(minI, minL);
    }
};
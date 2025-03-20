class Solution {
public:
    int countGoodSubstrings(string s) {
        int i  = 0;
        int j  = 0;
        int n  = s.size();
        int ans = 0;
        unordered_map<char,int>mp;
        while(i  < n && j < n){
            mp[s[j]]++;
            if(j - i + 1  < 3){
                j++;
            }else if(mp.size()==3){
              mp.erase(s[i]);
              i++;
              j++;
              ans++;
            }else{
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return 0;
        unordered_map<char,int>f;

        for(char c : s){
           f[c]++;
        }

        for(char c : t){
            if(!f[c]) return 0;
            f[c]--;
        }
        return true;

    }
};
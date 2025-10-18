class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int>freq1, freq2;
        for(int i=0;i<s.size();i++){
            if(freq1[s[i]]!=freq2[t[i]]) return 0;
            freq1[s[i]]=i+1;
            freq2[t[i]]=i+1;
        }
        return true;

    }
};
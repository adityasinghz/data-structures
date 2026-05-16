class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>freq;
        for(auto c : s) freq[c]++;

        for(auto c : t){
            if(!freq[c]) return false;
            freq[c]--;
        }

        return true;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        map<char, int>freq;

        for(auto c : s){
            freq[c]++;
        }

        for(auto c : t){
            if(freq[c]==0) return false;
            freq[c]--;
        }
        return true;
    }
};
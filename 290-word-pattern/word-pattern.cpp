class Solution {
public:
    bool wordPattern(string p, string s) {
        stringstream ss(s);
        string word;
        int len = 0;
        while(ss>>word){
             len++;
        }
        if(len!=p.size()) return false;
        ss.clear();
        ss.str(s);
        int i = 0;
        unordered_map<string,int>freq1; unordered_map<char,int>freq2;
        while(ss>>word){
            if(freq1[word]!=freq2[p[i]]) return false;
            freq1[word] = i +1;
            freq2[p[i]] = i +1;
            i++;
        }
        return true;
    }
};
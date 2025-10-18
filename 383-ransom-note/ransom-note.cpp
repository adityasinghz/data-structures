class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>freq1;
        for(auto c : magazine)freq1[c]++;
        
        for(auto c : ransomNote){
            if(freq1[c]<=0) return false;
            freq1[c]--;
        }
        return true;
    }
};
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>freq;
        int ans = 0;
        for(auto c : allowed)freq[c]++;
        for(auto word : words){
            int i=0;
            for(char c : word){
                if(freq.find(c)==freq.end())break;
                i++;
            }
            if(word.size()==i) ans++;
        }
        return ans;
    }
};
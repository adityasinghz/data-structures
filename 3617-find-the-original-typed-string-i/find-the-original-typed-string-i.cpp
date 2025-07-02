class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<int,int>mp;
        int ans = 1;
        for(int i = 1;i<word.size();i++){
            if(word[i]==word[i-1]) mp[word[i]]++;
        }
        for(auto it : mp){
            ans+=it.second;
        }
        return ans;
    }
};
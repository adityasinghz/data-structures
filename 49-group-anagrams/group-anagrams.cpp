class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        vector<vector<string>>res;
        for(int i=0;i<strs.size();i++){
            string sortedString = strs[i];
            sort(sortedString.begin(),sortedString.end());
            mp[sortedString].push_back(strs[i]);
        }
        for(auto m  : mp){
            res.push_back(m.second);
        }
        return res;
    }
};
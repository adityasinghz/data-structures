class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>>freq;
        vector<vector<string>>res;
        for(auto str : strs){
            string s = str;
            sort(s.begin() , s.end());
            freq[s].push_back(str);
        }
        for(auto fre : freq){
            res.push_back(fre.second);
        }
        return res;

    }
};
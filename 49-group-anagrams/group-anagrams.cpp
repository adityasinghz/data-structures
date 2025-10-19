class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>freq;
        vector<vector<string>>res;
        for(auto str : strs){
            string sortedString = str;
            sort(sortedString.begin(),sortedString.end());
            freq[sortedString].push_back(str);
        }
        for(auto f : freq) res.push_back(f.second);
        return res;
    }
};
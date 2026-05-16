class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>strArr;
        vector<vector<string>> ans;
        for(auto str : strs){
            string sortedStr = str;
            sort(sortedStr.begin(),sortedStr.end());
            strArr[sortedStr].push_back(str);
        }
        for(auto arr : strArr){
            ans.push_back(arr.second);
        }
        return ans;
    }
};
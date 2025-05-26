class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>> mp;
        for(auto str : strs){
             vector<int>counts(26,0);
             string s;
             for(int s : str){
                counts[s-'a']++;
             }
             for(int count : counts){
                s+= ( "#" + to_string(count));
             }
             mp[s].push_back(str);
        }

        for(auto m : mp){
            ans.push_back(m.second);
        }
        return ans;

    }
};
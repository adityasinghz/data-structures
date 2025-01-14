class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());

        int i =0;
        int j =0;
        string ans;
        while(i<strs[0].size() && j<strs[strs.size()-1].size()){
            if(strs[0][i]!=strs[strs.size()-1][j]) break;
               ans+=strs[0][i];
            i++;
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string first = strs[0];
        string last =  strs[n-1];

        int i = 0;
        int j = 0;

        string ans;

        while( i  < first.size() && j < last.size()){
            if(first[i] != last[j]) break;
            ans+=last[j];
            i++;
            j++;
        }
        return ans;
    }
};
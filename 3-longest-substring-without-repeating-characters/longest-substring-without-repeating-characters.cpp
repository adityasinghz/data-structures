class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        map<int,int>indexes;
        int ans = 0;
        while( j < s.size()){
            if(indexes.find(s[j])!=indexes.end() && indexes[s[j]] + 1 > i){ 
                i = indexes[s[j]] + 1;
            }
            cout<<" j "<<j<<' '<<" i "<<i<<'\n';
            ans = max(ans , j - i + 1);
            indexes[s[j]] = j;
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int i = 0;
        int j = 0;
        int l1 = s1.size();
        int l2 = s2.size();
        string ans;
        while( i < l1 && j < l2){
           ans+=s1[i++];
           ans+=s2[j++];
        }

        while( i < l1) ans+=s1[i++];
        while( j < l2) ans+=s2[j++];

        return ans;
    }
};
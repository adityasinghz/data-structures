class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        sort(s1.begin(), s1.end());
        for(int i=0; i < s2.size(); i++){
             string s = s2.substr(i,l1);
             sort(s.begin(),s.end());
             if(s == s1) return true;
        }
        return false;
    }
};
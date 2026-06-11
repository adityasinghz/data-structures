class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        int i = 0;
        int j = 0;
        sort(s1.begin(),s1.end());
        while( j < n){
           while(j - i + 1 < m) j++;
           if(j - i + 1 == m){
            string subString = s2.substr(i, j - i + 1);
            sort(subString.begin(),subString.end());
            if(s1 == subString) return true;
           }
           i++;
        }
        return false;
    }
};
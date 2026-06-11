class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int m = s1.size();
        int n = s2.size();
        int i = 0;
        int j = 0;
        vector<int>f1(26,0);
        vector<int>f2(26,0);
        for(auto c : s1) f1[c-'a']++;

        while( j < n){
           while(j - i + 1 <= m){f2[s2[j]-'a']++; j++;}
           if(f1 == f2) return true;
           f2[s2[i]-'a']--;
           i++;
        }
        return false;
    }
};
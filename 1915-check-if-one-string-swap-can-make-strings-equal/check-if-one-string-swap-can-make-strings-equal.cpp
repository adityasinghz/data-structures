class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        int ct = 0;
        char a = '\0';
        char b = '\0';
        for(int i = 0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(a=='\0' && b == '\0'){
                  a = s1[i]; // c
                  b = s2[i]; // a
                }else if(s1[i]!=b || s2[i]!=a){
                    return false;
                }
                 ct++;
            }
        }
        return ct==2;
    }
};
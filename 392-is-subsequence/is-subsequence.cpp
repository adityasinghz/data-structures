class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
        a  b   c
        a  h   b  g   d   c
        
        i  
        j
        0  
        */
        int shouldStart = 0;
        int prevIndx = -1;
        for(int i = 0;i<s.size();i++){
           for(int j=0;j<t.size();j++){
               if(s[i] == t[j] && j > prevIndx){
                  prevIndx = j; 
                  shouldStart++;
                  break;
               }
           }
        }
        return shouldStart==s.size();
    }
};
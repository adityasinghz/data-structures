class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        // "eulb si yks eht"
        int i = 0;
        int j = 0;
        int space = false;
        int n = s.size();

        while( j < n){
            while(i<n && s[i]==' ')i++;
            j=i;
            while(j<n && s[j]!=' ')j++;
            reverse(s.begin()+i,s.begin()+j);
            i=j;
        }
        
        i = 0;
        j = 0;

        while(i<n && s[i]==' ')i++; 

        while(i < n){
            if(s[i]!=' '){
              if(space){
              s[j++]=' ';
              }
              s[j++]=s[i];
              space = false;
            }else{
               space = true;
            }
            i++;
        }
        
        s.resize(j);
        return s;
    }
};
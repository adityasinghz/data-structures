class Solution {
public:
    bool isVowel(char c){
     return (tolower(c)=='a' || tolower(c)=='e' || tolower(c)=='i' || tolower(c)=='o' || tolower(c)=='u'); 
    }
    string reverseVowels(string s) {
        int i=0;
        int j = s.size()-1;
        int n = s.size();
        while( i < j){
          if(i < n && !isVowel(s[i])) i++;
          if(j >=0   &&!isVowel(s[j]))j--;

          if(isVowel(s[i]) && isVowel(s[j])) swap(s[i++], s[j--]);
        }
        return s;
    }
};
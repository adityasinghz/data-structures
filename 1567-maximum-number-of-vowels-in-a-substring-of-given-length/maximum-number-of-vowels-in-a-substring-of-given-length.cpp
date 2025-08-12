class Solution {
public:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;
        int count = 0;
        int len=0;
        int maxi = 0;
        while( j < s.size()){
            count+=(isVowel(s[j++]));
            len++;
            if(len==k){
               maxi = max(count,maxi);
               if(isVowel(s[i])) count--;
               len--;
               i++;
            }
        }
        return maxi;

    }
};
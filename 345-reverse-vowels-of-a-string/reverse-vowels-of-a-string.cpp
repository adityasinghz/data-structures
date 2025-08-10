class Solution {
public:
    bool isVowel(char c){
        return (tolower(c)=='a' || tolower(c)=='e' || tolower(c)=='i' || tolower(c)=='o' || tolower(c)=='u');
    }
    string reverseVowels(string s) {
        vector<int>indexes;
        string ans=s;
        for(int i=0;i<s.size();i++)
          if(isVowel(s[i])) indexes.push_back(i);

        reverse(indexes.begin(),indexes.end());
        int j = 0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])) ans[i] = s[indexes[j++]]; 
        }
        return ans;
    }
};
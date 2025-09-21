class Solution {
public:
    bool isPalindrome(string s) {
        string ori;
        for(auto c  : s) if(isalpha(c)|| isdigit(c))ori+=tolower(c);

        string rev = ori;
     
        reverse(rev.begin(),rev.end());
        cout<<ori<<' '<<rev;
        return rev==ori;
    }
};
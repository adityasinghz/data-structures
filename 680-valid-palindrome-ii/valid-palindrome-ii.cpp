class Solution {
public:
    bool validPalindrome(string s) {
        int low = 0;
        int high  = s.size() - 1;

        while(low < high){
           if(s[low]==s[high]){low++;high--;}
           else return isPalindrome(low+1,high,s) || isPalindrome(low,high-1,s);   
        }
        return true;
    }

    bool isPalindrome(int low, int high,string s){
        while(low < high){
            if(s[low++]!=s[high--]) return false;
        }
        return true;
    }
};
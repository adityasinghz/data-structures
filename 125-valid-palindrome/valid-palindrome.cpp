class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int low = 0;
        int high = n-1;

        while( low < high){
            while(low < high && !isalnum(s[low])) low++;
            while(low < high && !isalnum(s[high]))high--;
            if(tolower(s[low]) == tolower(s[high])) {low++;high--;}
            else return false;
        }
        return true;
    }
};
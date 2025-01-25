class Solution {
public:
    int myAtoi(string s) {
      int i = 0;

      while(s[i]==' '){
          i++;
      }
      int prod = 1;
      if(s[i]=='-'){ prod  = -1; i++;}
      else if(s[i]=='+'){ prod = 1; i++;}
      while(s[i]=='0') i++;
      if(s[i]-'0' < 0 || s[i]-'0'>9) return 0;
      long long int res = 0;
      while(s[i] - '0' >=0 && s[i] - '0' <=9){
        if((res*10 + s[i] - '0')*prod >= INT_MAX) return INT_MAX;
        if((res*10 + s[i] - '0')*prod <= INT_MIN) return INT_MIN;
        res = (res*10 + s[i] - '0');
        i++;
      }
      return res*prod ;
    }
};
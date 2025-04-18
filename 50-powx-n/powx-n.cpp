class Solution {
public:
    double myPow(double x, int nn) {
       bool isNeg = nn < 0 ? true : false;
       long long int n = nn;
       n = n < 0 ? -n : n;
       double ans = 1;
       while(n>0){
          if(n%2==0){
            x*=x;
            n/=2;
          }else{
            ans*=x;
            n--;
          }
       }
       return isNeg ? 1/ans:ans;
    }
};
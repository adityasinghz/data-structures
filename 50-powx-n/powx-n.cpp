class Solution {
public:
    double myPow(double x, int nn) {
        long long int n = nn;
        n = n<0 ? -n : n;
        double ans = (double)1;
        while(n > 0){
             if(n %2 != 0){
                ans*=x;
                n--;
             }else{
                x*=x;
                n/=2;
             }
        }
        return nn <0? (double)1/ans : ans;
    }
};
class Solution {
public:
    const int MOD = 1e9+7;
    long long int myPow(long long x , long long n){
        long long int ans = 1;
        while( n > 0){
            if(n%2!=0){
               ans= (ans * x) % MOD;
               n--;
            }else{
                x = (x * x) % MOD;
                n/=2;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long even  = (n+1)/2;
        long long odd = n/2;

        long long ans1  = myPow(5, even);
        long long ans2  = myPow(4, odd);

        return (ans1*ans2)%MOD;
    }
};
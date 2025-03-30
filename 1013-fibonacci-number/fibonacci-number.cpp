class Solution {
public:
    int dp[31];
    int fib(int n) {
        if(dp[n]) return dp[n];
        if(n==1 || n==0) return n;
        return dp[n] = fib(n-2) + fib(n-1);
    }
};
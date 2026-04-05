class Solution {
    private int solve(int m, int n, int[][] dp){
        if(m < 1 || n < 1) return 0;
        if(m == 1 && n == 1) return 1;
        if(dp[m][n]!=-1) return dp[m][n];

        return dp[m][n] = solve(m - 1,n,dp) + solve(m,n-1,dp); 
    }
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m+1][n+1];

        for(int i=0;i<=m;i++){
            Arrays.fill(dp[i],-1);
        }

        return solve(m,n,dp);
    }
}
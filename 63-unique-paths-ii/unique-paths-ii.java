class Solution {
    private int solve(int m, int n, int[][] grid, int[][] dp){
        if( m < 0 || n < 0 || grid[m][n]==1) return 0;
        
        if( m == 0 && n == 0) return 1;

        if(dp[m][n]!=-1) return dp[m][n];


        return dp[m][n] = solve(m-1,n,grid,dp) + solve(m,n-1,grid,dp);
    }
    public int uniquePathsWithObstacles(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m+1][n+1];
        for(int i=0;i<m;i++){
          Arrays.fill(dp[i],-1);
        }
        return solve(m-1,n-1,grid,dp);
    }
}
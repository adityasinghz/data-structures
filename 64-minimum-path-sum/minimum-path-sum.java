class Solution {

    private int solve(int m, int n, int[][] grid, int[][] dp){
        if(m < 0 || n < 0) return Integer.MAX_VALUE;
        if(m==0 && n ==0) return grid[m][n];
        if(dp[m][n]!=-1) return dp[m][n];
        int min = Math.min(solve(m-1,n,grid, dp), solve(m,n-1,grid, dp));
        if(min == Integer.MAX_VALUE) return min;
        return dp[m][n] = grid[m][n] + min; 
    }
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m+1][n+1];
        for(int i=0;i<m;i++){
            Arrays.fill(dp[i],-1);
        }
        return solve(m-1,n-1,grid, dp);
    }
}
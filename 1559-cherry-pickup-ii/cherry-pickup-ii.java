class Solution {
    private int solve(int i, int j1, int j2, int m , int n, int[][] grid, int[][][] dp){
        if( i >= m || j1 < 0 || j1 >=n || j2  < 0 || j2 >=n) return Integer.MIN_VALUE / 2;

        if( i == m-1 ){
            if( j1 == j2 ) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        int maxi = Integer.MIN_VALUE / 2;
        for(int dj1 = -1; dj1 < 2; dj1++){
            for(int dj2 = -1; dj2 < 2; dj2++){

                int val = 0;

                if(j1 == j2) val = grid[i][j1];
                else val = grid[i][j1] + grid[i][j2];

                val+=solve(i+1, j1+dj1, j2 + dj2, m, n, grid, dp);
                dp[i][j1][j2] =  maxi = Math.max(val,maxi);
            }
        }
        return maxi;
    } 

    public int cherryPickup(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][] dp = new int[m][n][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                Arrays.fill(dp[i][j], -1);
            }
        }
        return solve(0,0,n-1,m,n,grid, dp);
    }
}
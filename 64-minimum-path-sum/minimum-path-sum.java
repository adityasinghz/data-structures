class Solution {
    public int minPathSum(int[][] grid) {
        int m  = grid.length;
        int n  = grid[0].length;
        int[][] dp = new int[m][n];
        dp[0][0] = grid[0][0];
        for(int col=1; col < n; col++){
            dp[0][col]= dp[0][col-1] + grid[0][col]; 
        }
     
        for(int row=1; row < m; row++){
            dp[row][0] =  dp[row-1][0] + grid[row][0];
        }
        

        for(int i=1; i<m; i++){
           for(int j=1; j < n; j++){
               dp[i][j] = grid[i][j] + Math.min(dp[i-1][j], dp[i][j-1]);
           }
        }
        return dp[m-1][n-1];
    }
}
/*
  1 4 5
  2 7 6
  6 8 7

4
4
2
5
7
5
7
6

1  4  4
2  7  5
5  7  6

*/
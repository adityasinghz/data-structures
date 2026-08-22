class Solution {
public:
    int solve(int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if( m < 0 || n < 0) return INT_MAX;
        if(m==0 && n ==0) return grid[0][0];
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n] = grid[m][n] +  min( solve(m-1,n,grid, dp), solve(m,n-1,grid, dp) );
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if( i  == grid.size() - 1) return grid[i][j];
        if( dp[i][j] != INT_MIN) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve( i + 1 , j, grid, dp), solve(i + 1, j + 1, grid,dp));
    }
    int minimumTotal(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size());
        for(int i = 0; i < grid.size(); i++) dp[i] = vector<int>(grid[i].size(), INT_MIN);
        
        return solve(0,0,grid,dp);
    }
};
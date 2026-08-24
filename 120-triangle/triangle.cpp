class Solution {
public:
    int solve(int i, int j, int m, vector<vector<int>>&triangle, vector<vector<int>>&dp){
        if( i == m - 1   ) return triangle[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int down = solve(i+1,j,m,triangle, dp);
        int right = solve(i+1,j+1,m,triangle, dp);

        return dp[i][j] = triangle[i][j] + min(down, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,INT_MAX));
        return solve(0, 0,m, triangle, dp);
    }
};
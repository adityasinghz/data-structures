class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        vector<long long> prefixTop(n + 1, 0), prefixBottom(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixTop[i + 1] = prefixTop[i] + grid[0][i];
            prefixBottom[i + 1] = prefixBottom[i] + grid[1][i];
        }

        long long result = LLONG_MAX;

        for (int k = 0; k < n; k++) {
            long long topRemaining = prefixTop[n] - prefixTop[k + 1];   
            long long bottomRemaining = prefixBottom[k];              


            long long secondRobotPoints = max(topRemaining, bottomRemaining);

            result = min(result, secondRobotPoints);
        }

        return result;
    }
};


// 2 , 7 , 11
// 1 , 6,  7
// 
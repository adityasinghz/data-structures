class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int  n = grid.size();
        vector<int>ans(n*n+1, 0), res;
        int a_sum = 0;
        int sum = n*n * (n*n + 1)/2;
        for(int i = 0;i< grid.size(); i++){
            for(int j = 0;j <grid.size(); j++){
                 ans[grid[i][j]] = 1;
                 a_sum+=grid[i][j];
            }
        }
        for(int i = 1; i< ans.size() ; i++){
            if(!ans[i]) res.push_back(i);
        }
        res.push_back(abs(sum - (a_sum + res[0])));
        reverse(res.begin(),res.end());
        return res;
    }
};
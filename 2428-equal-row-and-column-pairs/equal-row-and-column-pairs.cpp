class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ct = 0;
        unordered_map<int,vector<int>>row, col;
        for(int i=0;i<m;i++){
            row[i] = grid[i];
        }
        
        for(int j = 0; j <n;j++){
            vector<int>temp;
            for(int i=0;i<m;i++){
                temp.push_back(grid[i][j]);
            }
            col[j] = temp;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(row[i] == col[j]) ct++;
            }
        }

        return ct;
    }
};
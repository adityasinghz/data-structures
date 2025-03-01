class Solution {
public:
    int find(int x, vector<int>& par) {
        if (x != par[x]) 
            par[x] = find(par[x], par); // Path Compression
        return par[x];
    }

    void disjoint(int x, int z, vector<int>& par, vector<int>& len) {
        int par_x = find(x, par);
        int par_z = find(z, par);

        if (par_x != par_z) {
            if (len[par_z] > len[par_x]) {
                par[par_x] = par_z;
                len[par_z] += len[par_x];
            } else {
                par[par_z] = par_x;
                len[par_x] += len[par_z];
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> len(m * n, 1);
        vector<int> par(m * n);
        vector<pair<int, int>> directions = {{-1,0}, {0,-1}, {0,1}, {1,0}};

        for (int i = 0; i < m * n; i++) par[i] = i;

        // Step 1: Connect adjacent 1s using union-find
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int origin = i * n + j;
                    for (auto [dx, dy] : directions) {
                        int row = i + dx, col = j + dy;
                        if (row >= 0 && col >= 0 && row < m && col < n && grid[row][col] == 1) {
                            disjoint(origin, row * n + col, par, len);
                        }
                    }
                }
            }
        }

        // Step 2: Compute size of each connected component
        unordered_map<int, int> freq;
        int max_area = 0;

        for (int i = 0; i < m * n; i++) {
            if (grid[i / n][i % n] == 1) {
                int parent = find(i, par); // Ensure ultimate parent is found
                freq[parent] = len[parent];
                max_area = max(max_area, len[parent]); // Keep track of largest island found so far
            }
        }

        // Step 3: Try flipping each '0' to '1' and compute new area
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int area = 1;
                    unordered_set<int> seen;
                    for (auto [dx, dy] : directions) {
                        int row = i + dx, col = j + dy;
                        if (row >= 0 && col >= 0 && row < m && col < n && grid[row][col] == 1) {
                            int parent = find(row * n + col, par);
                            if (seen.insert(parent).second) {
                                area += freq[parent];
                            }
                        }
                    }
                    max_area = max(max_area, area);
                }
            }
        }

        return max_area;
    }
};

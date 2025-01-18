class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
        int m = grid.size();
        int n = grid[0].size();
        q.push({0,{0,0}});
        vector<vector<int>>distance(m, vector<int>(n,INT_MAX));
        distance[0][0] = 0;
        while(!q.empty()){
           int cost = q.top().first;
           int i = q.top().second.first;
           int j = q.top().second.second;
           q.pop();
           int left =  cost + (grid[i][j] == 2 ? 0 : 1);
           int right =  cost + (grid[i][j] == 1 ? 0 : 1);
           int up =  cost + (grid[i][j] == 4 ? 0 : 1);
           int down =  cost + (grid[i][j] == 3 ? 0 : 1);
           if(i-1>=0 && distance[i-1][j] > up){  
             q.push({ up,{i-1,j}});
             distance[i-1][j] = up;
           }
           if(i+1<m  && distance[i+1][j] > down){   
            q.push({down,{i+1,j}});
            distance[i+1][j] = down;
           }
           if(j-1>=0 && distance[i][j-1] > left) { 
            q.push({left,{i,j-1}});
            distance[i][j-1] = left;
           }
           if(j+1<n  && distance[i][j+1] > right) {
             q.push({right, {i, j + 1}});
             distance[i][j+1] = right;
           }
        }
        return distance[m-1][n-1];
    }
};
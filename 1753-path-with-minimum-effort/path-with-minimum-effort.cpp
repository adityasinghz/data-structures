class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
        vector<int>distance(m*n, INT_MAX);
        q.push({0,{0,0}});
        distance[0] = 0;
        vector<pair<int,int>>directions={{0,-1},{-1,0},{1,0},{0,1}};
        while(!q.empty()){
            int d = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            for(auto direction : directions){

                int row = x + direction.first;
                int col = y + direction.second;

                if(row < 0 || row >= m || col < 0 || col >= n ) continue;
               
                int diff = abs(heights[x][y] - heights[row][col]);

                int dist = max(d, diff);
 
                int neighbour  = row * n + col;
        
                if(distance[neighbour] >  dist){
                    distance[neighbour] = dist;
                    q.push({dist,{row,col}});
                }
            }
        }

        return distance[m*n-1];
    }
};
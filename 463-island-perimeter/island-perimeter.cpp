class Solution {
public:
    int bfs(int left, int right,vector<vector<int>>&matrix, map<pair<int,int>,bool>&visited){
  vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
  visited[make_pair(left,right)] = true; 
  int m = matrix.size();
  int n = matrix[0].size();
  queue<pair<int,int>>q;
  int peri = 0;
  q.push(make_pair(left,right));
  while(!q.empty()){
    left = q.front().first;
    right = q.front().second;
    q.pop();
    int points = 4;
    for(auto direction : directions){
        int l = left +  direction[0];
        int r = right + direction[1];
        if( l >=m || r >=n || l < 0 || r < 0 || matrix[l][r]==0) continue;
        points--; 
        if(visited[make_pair(l,r)]) continue;
        visited[make_pair(l,r)] = true; 
        q.push(make_pair(l,r));
    }
    peri+=points;
  }
  return peri;
}
    int islandPerimeter(vector<vector<int>>& matrix) {
     map<pair<int,int>,bool>visited;
     int m = matrix.size();
     int n = matrix[0].size();
     int peri = 0;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
             if(visited[make_pair(i,j)] || !matrix[i][j])continue;
             peri+=bfs(i, j,matrix,visited);
        } 
     }
     return peri;
    }
};
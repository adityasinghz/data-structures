class Solution {
public:
    void bfs(int sr, int sc,int color, int comCol,vector<vector<int>>& image){
        queue<pair<int,int>>q;
        map<pair<int,int>,bool>visited;
        int m = image.size();
        int n = image[0].size();
        q.push({sr,sc});
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            if(i+1<m&&image[i+1][j]==comCol&&!visited[{i+1,j}]){
               q.push({i+1,j});
               visited[{i+1,j}]=true;
               image[i+1][j]=color;
            }
            if(j+1<n&&image[i][j+1]==comCol&&!visited[{i,j+1}]){
               q.push({i,j+1});
               visited[{i,j+1}]=true;
               image[i][j+1]=color;
            }
            if(i-1>=0&&image[i-1][j]==comCol&&!visited[{i-1,j}]){
               q.push({i-1,j});
               visited[{i-1,j}]=true;
               image[i-1][j]=color;
            }
            if(j-1>=0&&image[i][j-1]==comCol&&!visited[{i,j-1}]){
               q.push({i,j-1});
               visited[{i,j-1}]=true;
               image[i][j-1]=color;
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int comCol = image[sr][sc];
        image[sr][sc]=color;
        bfs(sr,sc,color, comCol,image);
        return image;
    }
};
class Solution {
public:

    int find(int x , vector<int>&par){
       if(x == par[x]) return x;
       return par[x] = find(par[x] , par);
    }

    void disjoint( int x , int z , vector<int>&par, vector<int>&len){
       
       int par_x = find(x , par);
       int par_z = find(z , par);

       if(par_x != par_z){
         
         if(len[par_z] > len[par_x]){
            len[par_z] += len[par_x];
            par[par_x] = par_z;
         }else{
            len[par_x]+=len[par_z];
            par[par_z] = par_x;
         }

       }
    } 
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>len(m*n,1);
        vector<int>par(m*n);
         
        vector<pair<int,int>>directions = {{-1,0}, {0,-1}, {0,1} , {1, 0}};

        for(int i=0;i<par.size();i++){
            par[i] = i;
        }
        for( int i = 0; i <m ; i++){
            for(int j = 0; j< n ; j++){
                int origin  = i*m + j;
                if(grid[i][j] == 1){
                     for(auto direction : directions){
                        int row = i + direction.first;
                        int col = j + direction.second;
                        int neighbor  = row*m + col;

                        if(row < 0 || col < 0 || row >= m || col >= n || !grid[row][col])continue;
                         
                        disjoint(origin , neighbor, par, len);
                        
                     }
                }
            }
        }

        unordered_map<int, int> freq;
        int max_area = 0;

        for (int i = 0; i < m * n; i++) {
            if (grid[i / n][i % n] == 1) {
                int parent = find(i, par); // Ensure ultimate parent is found
                freq[parent] = len[parent];
                max_area = max(max_area, len[parent]); // Keep track of largest island found so far
            }
        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0){
                    int area = 1;
                    unordered_set<int>st;
                    for(auto direction : directions){
                      int row =  i + direction.first;
                      int col =  j + direction.second;
                      if(row < 0 || col < 0 || row >= m || col >= n || !grid[row][col])continue;
                      int ori =  row*m+col;
                      int parent =find(par[ori],par);
                      if(st.find(parent)==st.end()){
                        area+=freq[parent];
                        st.insert(parent);
                      }
                    }
                    max_area = max(max_area, area); 
                }
            }
        }
       
        
        return max_area;
    }
};

/*

[[1,0,1],
 [0,0,0],
 [0,1,1]]


*/
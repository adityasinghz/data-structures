class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>position;
        for(int i=0;i<mat.size();i++){
            for(int j = 0;j<mat[i].size();j++){
                position[mat[i][j]] = make_pair(i,j);
            }
        }
         
        unordered_map<int,int>rows;
        unordered_map<int,int>cols;

        for(int i = 0;i<arr.size();i++){
            auto [row,col] = position[arr[i]];
            rows[row]++;
            cols[col]++;

            if(rows[row]==mat[0].size() || cols[col]==mat.size()) return i; 
        }

        return -1;

    }
};
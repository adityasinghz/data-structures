class NumMatrix {
public:
    vector<vector<int>>prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        prefixSum = vector<vector<int>>(rows,vector<int>(cols,0));
        
        for(int i=0; i < rows; i++){
            prefixSum[i][0] = matrix[i][0];
            for(int j = 1; j < cols; j++){
                prefixSum[i][j] = prefixSum[i][j-1] + matrix[i][j];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int i=row1;i<=row2;i++){
            if(col1 > 0){
                res+=prefixSum[i][col2] - prefixSum[i][col1-1];  
            }else{
                res+=prefixSum[i][col2];
            }
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);

1, 2, 3, 4, 5

1, 
 */
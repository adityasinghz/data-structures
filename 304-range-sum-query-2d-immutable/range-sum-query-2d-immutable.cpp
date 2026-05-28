class NumMatrix {
public:
    vector<vector<int>>subMat;
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(); int col = matrix[0].size();
        subMat = vector<vector<int>>(row+1,vector<int>(col+1,0));
        for(int i=0;i<row;i++){
            int prefix = 0;
            for(int j=0;j<col;j++){
               prefix+=matrix[i][j];
               int above = subMat[i][j+1];
               subMat[i+1][j+1] = prefix + above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;

        int bottomRight = subMat[row2][col2];
        int topLeft = subMat[row1-1][col1-1];
        int topRight = subMat[row1-1][col2];
        int bottomLeft = subMat[row2][col1-1];

        return bottomRight - topRight - bottomLeft + topLeft;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
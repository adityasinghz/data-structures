class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int colCheck = false;
        int rowCheck = false;

        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0) rowCheck = true;
        }

        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]==0) colCheck = true;
        }

        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int j = 1;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                for(int i=1;i<matrix.size();i++){
                    matrix[i][j]=0;
                }
            }
        }

        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]==0){
                for(int j=1;j<matrix[0].size();j++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(colCheck){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j] = 0;
            }
        }

        if(rowCheck){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0] = 0;
            }
        }



    }
};
class Solution {
public:
    bool isRowValid(int row, vector<vector<char>>&board){
        unordered_map<char,int>rows;
        for(int col=0;col<9;col++){
            if(board[row][col] == '.') continue;
            if(rows.find(board[row][col])!=rows.end()) return false;
            rows[board[row][col]] = true;
        }
        return true;
    }
    bool isColValid(int col, vector<vector<char>>&board){
       unordered_map<char,int>cols;
        for(int row=0;row<9;row++){
            if(board[row][col] == '.') continue;
            if(cols.find(board[row][col])!=cols.end()) return false;
            cols[board[row][col]] = true;
        }
        return true;
    }
    bool isgridValid(int row, int col, vector<vector<char>>&board){
          unordered_map<char,int>rowCols;
          int m = board.size();
          int n = board[0].size();
          for(int i=row; i < row + 3; i++){
               for(int j=col; j < col + 3; j++){
                 if(board[i][j] == '.') continue;
                 if(rowCols.find(board[i][j])!=rowCols.end()) return false;
                 rowCols[board[i][j]] = true;
               }
          }
          return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int row =0; row<9; row++) if(!isRowValid(row, board)) return false;
   
        for(int col =0; col<9; col++) if(!isColValid(col, board)) return false;
            
        for(int row = 0; row < 9; row+=3){
           for(int col = 0; col < 9; col+=3){
               if(!isgridValid(row, col, board)) return false;
           }
        }
        return true;
    }
};
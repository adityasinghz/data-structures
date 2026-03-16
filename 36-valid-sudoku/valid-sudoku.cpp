class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       
        for(int i=0;i<9;i++){
            unordered_map<char,bool>rows;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(rows[board[i][j]]) return false;
                rows[board[i][j]] = true;
            }
        }
        cout<<"Rows\n";
        
        for(int j = 0;  j < 9; j++){
            unordered_map<char,bool>cols;
            for(int i = 0; i < 9; i++){
                if(board[i][j]=='.') continue;
                if(cols[board[i][j]]) return false;
                cols[board[i][j]] = true;
            }
        }
        
        cout<<"Cols\n";
        for(int i = 0; i < 9; i+=3){
            for(int j = 0 ; j < 9; j+=3){
                unordered_map<char, bool>grids;
                cout<<i<<' '<<j<<'\n';
                for(int row = i; row < i + 3; row++){
                    for(int col = j; col < j + 3; col++){
                       if(board[row][col]=='.') continue;
                       if(grids[board[row][col]]) return false;
                       grids[board[row][col]] = true;
                    }
                }
            }
        }
        cout<<"Grid\n";
        return true;
    }
};
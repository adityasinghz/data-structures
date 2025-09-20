class Solution {
public:
    bool rowCheck(int row, int col, vector<vector<char>>& board, unordered_map<char,bool>freq){
         for(int i=row;i<board.size();i++){
             if(!isdigit(board[i][col])) continue;
             if(freq[board[i][col]]) return false;
             freq[board[i][col]] = true;
         }
         return true;
    }

    bool colCheck(int row, int col, vector<vector<char>>& board, unordered_map<char,bool>freq){
            for(int j=col;j<board[0].size();j++){
             if(!isdigit(board[row][j])) continue;
             if(freq[board[row][j]]) return false;
             freq[board[row][j]] = true;
            }
            return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                unordered_map<char,bool>freq;
                bool rowValid = rowCheck(i, j,board, freq);
                bool colValid = colCheck(i, j,board, freq);
                if(!rowValid) return false;
                if(!colValid) return false;
            }
        }
        cout<<"alive\n";
        for(int boxRow=0;boxRow<m;boxRow+=3){
            for(int boxCol=0;boxCol<n;boxCol+=3){
            unordered_map<char,bool>freq;
            for(int i=boxRow;i<boxRow+3;i++){
                for(int j=boxCol;j<boxCol+3;j++){
                    if(!isdigit(board[i][j])) continue;
                    if(freq[board[i][j]]) return false;
                    freq[board[i][j]] = true;
                }
            }
            cout<<'\n';
            }
        }    
        return true;
    }
};
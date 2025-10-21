class Solution {
    private:
    bool helper(vector<vector<char>>& board,int row,int col){
        int n = board.size();
        int m = board[0].size();
        char element = board[row][col];
        board[row][col] = '.';

        for(int j = 0;j<m;j++){
            if(board[row][j] != '.'){
                if (board[row][j] == element) return false;
            }
        }
        for(int i = 0;i<n;i++){
            if(board[i][col] != '.'){
                if (board[i][col] == element) return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if(board[i][j] != '.'){
                    if (board[i][j] == element) return false;
                }
            }
        }

        board[row][col] = element;
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] != '.'){
                    if(!helper(board,i,j))return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // check row
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == num) return false;
        }

        // check column
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == num) return false;
        }

        // check 3x3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[startRow + i][startCol + j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') {
                    
                    for(char num = '1'; num <= '9'; num++) {

                        if(isValid(board, i, j, num)) {

                            board[i][j] = num;

                            if(solve(board))
                                return true;

                            // backtrack
                            board[i][j] = '.';
                        }
                    }

                    return false; // no number works
                }
            }
        }

        return true; // solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
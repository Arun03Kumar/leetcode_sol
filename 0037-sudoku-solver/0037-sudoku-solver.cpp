class Solution {
public:
    bool is_valid(vector<vector<char>> &board, int row, int col, int ch) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;

            int r = row / 3 * 3 + i / 3;
            int c = col / 3 * 3 + i % 3;

            if(board[r][c] == ch) return false;
        }

        // int c_t_row = row / 3 * 3;
        // int c_t_col = col / 3 * 3;

        // for(int j = 0; j < 3; j++) {
        //     for(int k = 0; k < 3; k++) {
        //         if(board[c_t_row + j][c_t_col + k] == ch) {
        //             return false;
        //         }
        //     }
        // } 

        return true;
    }
    bool recursion(vector<vector<char>> &board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(is_valid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if(recursion(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        recursion(board);
    }
};
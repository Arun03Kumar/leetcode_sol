class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c, vector<vector<int>> &visited) {
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == 'X' || visited[r][c] == 1) {
            return;
        }

        visited[r][c] = 1;

        dfs(board, r + 1, c, visited);
        dfs(board, r - 1, c, visited);
        dfs(board, r, c + 1, visited);
        dfs(board, r, c - 1, visited);
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                if((r == 0 || r == row - 1 || c == 0 || c == col - 1) && board[r][c] == 'O' && visited[r][c] == 0) {
                    dfs(board, r, c, visited);
                }
            }
        }

        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                if(board[r][c] == 'O' && visited[r][c] != 1) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
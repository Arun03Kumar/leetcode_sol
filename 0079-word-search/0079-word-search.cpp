class Solution {
public:
    bool backtracking(vector<vector<char>>& arr, int i, int j, int idx, string word) {
        if(idx == word.size()) return true;
        if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == '$') return false;

        if(arr[i][j] != word[idx]) return false;

        char temp = arr[i][j];
        arr[i][j] = '$';
        bool a = backtracking(arr, i + 1, j, idx + 1, word);
        bool b = backtracking(arr, i, j + 1, idx + 1, word);
        bool c = backtracking(arr, i - 1, j, idx + 1, word);
        bool d = backtracking(arr, i, j - 1, idx + 1, word);
        arr[i][j] = temp;

        return a || b || c || d;
    }

    bool exist(vector<vector<char>>& board, string word) {

        // we will start the searching when the first char of word is matched with first char of grid
        // when current index is visited replace that charcter with another character
        // code is simillar to DFS

        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    bool ans = backtracking(board, i, j, 0, word);
                    if(ans) return true;
                }
            }
        }

        return false;
    }
};
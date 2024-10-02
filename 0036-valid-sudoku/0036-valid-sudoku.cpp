class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            unordered_set<int> st;
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] != '.') {
                    if(st.find(board[i][j]) != st.end()) return false;
                    else st.insert(board[i][j]);
                }
            }
        }

        for(int i = 0; i < board.size(); i++) {
            unordered_set<int> st;
            for(int j = 0; j < board[0].size(); j++) {
                if(board[j][i] != '.') {
                    if(st.find(board[j][i]) != st.end()) return false;
                    else st.insert(board[j][i]);
                }
            }
        }

        for(int i = 0; i < board.size(); i += 3) {
            for(int j = 0; j < board[0].size(); j += 3) {
                unordered_set<int> st;
                for(int m = 0; m < 3; m++) {
                    for(int n = 0; n < 3; n++) {

                        if(board[i + m][j + n] != '.') {
                            if(st.find(board[i + m][j + n]) != st.end()) {
                                return false;
                            }
                            else {
                                st.insert(board[i + m][j + n]);
                            }
                        }

                    }
                }
            }
        }

        return true;
    }
};
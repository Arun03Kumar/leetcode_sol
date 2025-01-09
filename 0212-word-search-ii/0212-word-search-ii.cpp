class TrieNode {
public:
    bool isTerminal;
    string endWord;
    vector<TrieNode*> children;

    TrieNode() {
        isTerminal = false;
        endWord = "";
        children.resize(26, nullptr);
    } 
};

class Solution {
public:
    void insert(TrieNode *root, string word) {
        TrieNode *temp = root;
        for(char ch: word) {
            if(temp -> children[ch - 'a'] == nullptr) {
                temp -> children[ch - 'a'] = new TrieNode();
            }
            temp = temp -> children[ch - 'a'];
        }

        temp -> isTerminal = true;
        temp -> endWord = word;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *root, vector<string> &ans) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '$' || root -> children[board[i][j] - 'a'] == nullptr) {
            return;
        }

        root = root -> children[board[i][j] - 'a'];

        if(root -> isTerminal) {
            ans.push_back(root -> endWord);
            root -> isTerminal = false;
        }

        char ch = board[i][j];
        board[i][j] = '$';

        dfs(board, i + 1, j, root, ans);
        dfs(board, i - 1, j, root, ans);
        dfs(board, i, j + 1, root, ans);
        dfs(board, i, j - 1, root, ans);

        board[i][j] = ch;
    } 

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        TrieNode *root = new TrieNode();
        for(string &s: words) {
            insert(root, s);
        }

        vector<string> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                char ch = board[i][j];
                if(root -> children[ch - 'a'] != nullptr) {
                    dfs(board, i, j, root, ans);
                }
            }
        }

        return ans;
    }
};
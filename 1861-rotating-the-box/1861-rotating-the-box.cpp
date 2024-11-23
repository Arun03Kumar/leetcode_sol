class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int r = j;
                int c = m - i - 1;
                ans[r][c] = box[i][j];
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = n - 1; j >= 0; j--) {
                if(ans[j][i] == '.') {
                    for(int k = j - 1; k >= 0; k--) {
                        if(ans[k][i] == '*') break;
                        else if(ans[k][i] == '#') {
                            ans[j][i] = '#';
                            ans[k][i] = '.';
                            break;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }

        return ans;
    }
};
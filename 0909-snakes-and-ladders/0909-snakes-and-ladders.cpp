class Solution {
public:
    pair<int, int> get_coord(int num, int n) {
        int row = (num - 1) / n;
        int row_bottom = (n - 1) - row;

        int col = (num - 1) % n;
        if((n % 2 == 0 && row_bottom % 2 == 0) || (n % 2 == 1 && row_bottom % 2 == 1)) {
            col = (n - 1) - col;
        }

        return {row_bottom, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        queue<int> q;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        visited[n - 1][0] = 1;
        q.push(1); // this is 1, board[n-1][0] = 1

        int ans = 0;

        while(!q.empty()) {

            int N = q.size();

            while(N--) {

                int front = q.front();
                q.pop();

                if(front == n * n) return ans;

                for(int k = 1; k <= 6; k++) {

                    if(front + k > n * n) break;

                    pair<int, int> coord = get_coord(front + k, n);
                    int row = coord.first;
                    int col = coord.second;

                    if(visited[row][col] == true) continue;

                    visited[row][col] = true;
                    if(board[row][col] == -1) {
                        q.push(front + k);
                    }
                    else {
                        q.push(board[row][col]);
                    }

                }

            }

            ans++;

        }

        return ans;
    }
};
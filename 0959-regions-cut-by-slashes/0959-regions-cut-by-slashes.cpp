class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>> &arr, vector<vector<int>> &visited, int i, int j) {
        if(i < 0 || i >= arr.size() || j < 0 || j >= arr.size() || visited[i][j] == 1 || arr[i][j] == 1) {
            return;
        }

        visited[i][j] = 1;

        for(auto dir: directions) {

            int new_r = i + dir[0];
            int new_c = j + dir[1];

            dfs(arr, visited, new_r, new_c);

        }
    }
    int regionsBySlashes(vector<string>& grid) {
        // if we replace '/' and '\\' with 1 and '' with 0 and form a matrix and find the components with 0s then it will satisfy the 1st example. but will fail for other
        // hence we can go for 2*2 matirx for each one representation but that will also fail for 3rd example.
        // hence go for 3*3 matrix representation of each character
        // '/'----->      [0 0 1]
        //                [0 1 0]
        //                [1 0 0]


        // '\\'----->      [1 0 0]
        //                 [0 1 0]
        //                 [0 0 1]

        // for '' all 0s in the 3*3 matrix
        // simply do the dfs and find the components of 0s

        int n = grid.size();
        vector<vector<int>> arr(n * 3, vector<int>(n * 3, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '/') {
                    arr[i * 3][j * 3 + 2] = 1;
                    arr[i * 3 + 1][j * 3 + 1] = 1;
                    arr[i * 3 + 2][j * 3] = 1;
                }
                else if(grid[i][j] == '\\') {
                    arr[i * 3][j * 3] = 1;
                    arr[i * 3 + 1][j * 3 + 1] = 1;
                    arr[i * 3 + 2][j * 3 + 2] = 1;
                }

            }
        }

        vector<vector<int>> visited(n * 3, vector<int>(n * 3, 0));
        int ans = 0;

        for(int i = 0; i < n * 3; i++) {
            for(int j = 0; j < n * 3; j++) {
                if(arr[i][j] == 0 && !visited[i][j]) {
                    dfs(arr, visited, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};
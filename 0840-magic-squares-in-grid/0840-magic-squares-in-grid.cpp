class Solution {
public:
    bool is_magical(vector<vector<int>> &grid, int row, int col) {

        unordered_set<int> st;

        // this is to check if all elements in the 3*3 grid are 1 to 9 and they are uniquely present
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {

                int num = grid[row + i][col + j];
                if(num <= 0 || num > 9 || st.count(num)) {
                    return false;
                }
                else {
                    st.insert(num);
                }

            }
        }

        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];

        for(int i = 0; i < 3; i++) {
            int temp = grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2];
            if(temp != sum) {
                return false;
            }
        }

        for(int i = 0; i < 3; i++) {
            int temp = grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i];
            if(temp != sum) {
                return false;
            }
        }

        int d1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int d2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

        if(d1 != sum || d2 != sum) return false;

        return true;

    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i + 2 < grid.size(); i++) {
            for(int j = 0; j + 2 < grid[0].size(); j++) {

                if(is_magical(grid, i, j)) {
                    count++;
                }

            }
        }

        return count;
    }
};
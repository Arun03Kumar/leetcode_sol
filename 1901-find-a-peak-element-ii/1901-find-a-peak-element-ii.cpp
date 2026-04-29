class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int row = 0, col = 0;
        vector<int> ans;
        while(row < m && col < n) {
            int left = col > 0 ? mat[row][col - 1] : -1;
            int right = col < n - 1 ? mat[row][col + 1] : -1;
            int top = row > 0 ? mat[row - 1][col] : -1;
            int bottom = row < m - 1 ? mat[row + 1][col] : -1;
            int curr = mat[row][col];
            
            if(curr > left && curr > right && curr > top && curr > bottom) {
                ans.push_back(row);
                ans.push_back(col);
                break;
            }
            else {
                if(left > curr && left > right && left > top && left > bottom) {
                    col = col - 1;
                }
                else if(right > curr && right > left && right > top && right > bottom) {
                    col = col + 1;
                }
                else if(top > curr && top > left && top > right && top > bottom) {
                    row = row - 1;
                }
                else row = row + 1;
            } 
        }   
        return ans;
    }
};
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = (left + right) / 2;

            int max_in_col_idx = 0;
            for(int i = 0; i < m; i++) {
                if(mat[i][mid] > mat[max_in_col_idx][mid]) {
                    max_in_col_idx = i;
                }
            }
            int left_val = (mid > 0) ? mat[max_in_col_idx][mid - 1] : -1;
            int right_val = (mid < n - 1) ? mat[max_in_col_idx][mid + 1] : -1;

            if(mat[max_in_col_idx][mid] > left_val && mat[max_in_col_idx][mid] > right_val) {
                return {max_in_col_idx, mid};
            }
            else if(left_val > mat[max_in_col_idx][mid]) right = mid - 1;
            else left = mid + 1;
        }
        return {-1, -1};
    }
};
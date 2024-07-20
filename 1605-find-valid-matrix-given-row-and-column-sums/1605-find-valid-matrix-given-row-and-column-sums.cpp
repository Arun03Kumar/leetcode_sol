class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // take minimum of rowSum[i] and colSum[j] this way we would be taking care of either one row or one column.

        // if any row or col value becomes 0 update the pointer.

        int m = rowSum.size();
        int n = colSum.size();

        int i = 0, j = 0;
        vector<vector<int>> ans(m, vector<int>(n, 0));

        while(i < m && j < n) {

            ans[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];

            if(rowSum[i] == 0) {
                i++;
            }

            if(colSum[j] == 0) {
                j++;
            }

        }

        return ans;
    }
};
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> index;
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int val = mat[i][j];
                index[val] = {i, j};
            }
        }

        vector<int> rows(m, n), cols(n, m);

        int ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            int x = arr[i];
            int r = index[x][0];
            int c = index[x][1];

            rows[r]--;
            cols[c]--;

            if(rows[r] == 0 || cols[c] == 0){
                ans = i;
                break;
            }
        }

        return ans;
    }
};
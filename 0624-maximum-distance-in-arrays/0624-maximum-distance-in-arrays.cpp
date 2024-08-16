class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        int x = arrays[0].size();
        int min_el = arrays[0][0], max_el = arrays[0][x - 1], ans = 0;
        for(int i = 1; i < arrays.size(); i++) {
            int temp1 = abs(arrays[i][0] - max_el);
            int n = arrays[i].size();
            int temp2 = abs(min_el - arrays[i][n - 1]);
            ans = max({ans, temp1, temp2});

            min_el = min(min_el, arrays[i][0]); 
            max_el = max(max_el, arrays[i][n - 1]); 
        }

        return ans;
    }
};
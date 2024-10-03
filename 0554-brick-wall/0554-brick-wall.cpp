class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // just store the cracks positions for each row then subtract them from the number of rows to get the bricks cut
        unordered_map<int, int> mp;
        int m = wall.size();
        int len = accumulate(begin(wall[0]), end(wall[0]), 0);
        for(int i = 0; i < m; i++) {
            int gap = 0;
            for(int j = 0; j < wall[i].size(); j++) {
                gap += wall[i][j];
                if(gap < len) {
                    mp[gap]++;
                }
            }
        }

        int ans = m;
        for(auto &[key, val]: mp) {
            ans = min(ans, m - val);
        }

        return ans;
    }
};
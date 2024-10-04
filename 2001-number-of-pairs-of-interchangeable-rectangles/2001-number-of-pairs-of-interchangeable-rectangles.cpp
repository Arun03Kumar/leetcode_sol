class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> mp;
        for(vector<int> &x: rectangles) {
            mp[(double)x[0] / (double)x[1]]++;
        }

        long long ans = 0;
        for(vector<int> &x: rectangles) {
            double temp = (double)x[0] / (double)x[1];
            ans += mp[temp] - 1;

            mp[temp]--;
        }

        return ans;
    }
};
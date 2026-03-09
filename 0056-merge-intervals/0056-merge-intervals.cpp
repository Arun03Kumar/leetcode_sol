class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            vector<int> &last = ans.back();
            if(intervals[i][0] > last[1]) {
                ans.push_back(intervals[i]);
            }
            else {
                last[1] = max(last[1], intervals[i][1]);
            }
        }

        return ans;
    }
};
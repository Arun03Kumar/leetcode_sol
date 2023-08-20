class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // if(intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end());
        int idx = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= intervals[idx][1]) {
                vector<int> v = {intervals[idx][0], max(intervals[idx][1], intervals[i][1])};
                intervals[idx] = v;
            } else{
                idx++;
                intervals[idx] = intervals[i];
            }
            // cout << intervals[idx][0]<<intervals[idx][1] << " "<<endl;
        }
        // cout << idx;
       vector<vector<int>> v;
       for(int i = 0; i <= idx; i++) {
           v.push_back(intervals[i]);
       }
       return v;
    }
};
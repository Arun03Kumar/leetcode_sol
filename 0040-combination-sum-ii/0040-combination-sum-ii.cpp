class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>> &ans, vector<int> &temp, int idx, int target) {
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i - 1]) continue;

            temp.push_back(candidates[i]);
            solve(candidates, ans, temp, i + 1, target - candidates[i]);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        solve(candidates, ans, temp, 0, target);
        return ans;
    }
};
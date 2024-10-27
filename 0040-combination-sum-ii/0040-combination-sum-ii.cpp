class Solution {
public:
    void backtracking(vector<int> &nums, int idx, int target, vector<int> &curr, vector<vector<int>> &ans) {
        if(target < 0) return;

        if(idx >= nums.size()) {
            if(target == 0) {
                ans.push_back(curr);
            }
            return;
        }

        curr.push_back(nums[idx]);
        backtracking(nums, idx + 1, target - nums[idx], curr, ans);

        curr.pop_back();
        int temp = nums[idx];
        while(idx < nums.size() && nums[idx] == temp) idx++;
        backtracking(nums, idx, target, curr, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // it is simillar to subset sum II problem, when we do not want to include a number then we skip all it occurances
        
        vector<vector<int>> ans;
        vector<int> curr;

        sort(begin(candidates), end(candidates));
        backtracking(candidates, 0, target, curr, ans);
        return ans;
    }
};
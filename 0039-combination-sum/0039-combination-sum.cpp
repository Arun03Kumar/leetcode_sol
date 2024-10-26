class Solution {
public:
    void backtracking(vector<int> &nums, int idx, vector<int> &curr, vector<vector<int>> &ans, int target) {
        if(idx == nums.size()) {
            if(target == 0) {
                ans.push_back(curr);
            }
            return;
        }

        if(nums[idx] <= target) {
            curr.push_back(nums[idx]);
            backtracking(nums, idx, curr, ans, target - nums[idx]);
            curr.pop_back();
        }

        backtracking(nums, idx + 1, curr, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // similar to finding subset problem but here we can send initial target and when current element is smaller than the target then we can choose in our answer, and send reduced target but with same index position because we can choose multiple times the same element
        // if current element can't be taken then increase the index
        vector<vector<int>> ans;
        vector<int> curr;
        backtracking(candidates, 0, curr, ans, target);

        return ans;
    }
};
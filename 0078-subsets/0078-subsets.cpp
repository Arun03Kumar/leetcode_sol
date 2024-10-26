class Solution {
public:
    void backtracking(vector<int> &nums, int idx, vector<int> &curr, vector<vector<int>> &all) {
        if(idx >= nums.size()) {
            all.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        backtracking(nums, idx + 1, curr, all);

        curr.pop_back();
        backtracking(nums, idx + 1, curr, all);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> all_subsets;
        vector<int> curr_subset;

        backtracking(nums, 0, curr_subset, all_subsets);
        return all_subsets;
    }
};
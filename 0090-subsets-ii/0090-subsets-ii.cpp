class Solution {
public:
    void backtracking(vector<int> &nums, int idx, vector<int> &curr, vector<vector<int>> &ans) {
        if(idx >= nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        backtracking(nums, idx + 1, curr, ans);

        curr.pop_back();
        int temp = nums[idx];
        while(idx < nums.size() && nums[idx] == temp) idx++;
        backtracking(nums, idx, curr, ans);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // this is similar to creating the subsets but with a small catch that when we don't want to include an element then we just pop back from the current array
        // but it may possible that we may get the same element afterwards which will again create the same copy as when it is being included
        // hence to avoid this first sort the array
        // and when we do not want to include it simply skip all the indices which contains that element
        
        vector<vector<int>> all_subsets;
        vector<int> curr;

        sort(begin(nums), end(nums));
        backtracking(nums, 0, curr, all_subsets); 
        return all_subsets;
    }
};
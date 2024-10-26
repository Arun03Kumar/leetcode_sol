class Solution {
public:
    void backtracking(vector<int> &nums, int idx, int skip_pos, vector<int> &curr, vector<vector<int>> &ans, unordered_set<int> &st) {
        if(idx >= nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(st.find(nums[i]) == st.end()) {
                curr.push_back(nums[i]);
                st.insert(nums[i]);
                backtracking(nums, idx + 1, i, curr, ans, st);
                curr.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    void recursion(vector<int> &nums, int idx, vector<vector<int>> &ans) {
        if(idx >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            recursion(nums, idx + 1, ans);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // vector<vector<int>> ans;
        // vector<int> curr;
        // unordered_set<int> st;

        // backtracking(nums, 0, -1, curr, ans, st);
        // return ans;


        // Approach 2: using swaps
        // we can swap each element with each element, but in the next call if we start from the start then we will get multiple same answers

        vector<vector<int>> ans;
        recursion(nums, 0, ans);
        return ans;
    }
};
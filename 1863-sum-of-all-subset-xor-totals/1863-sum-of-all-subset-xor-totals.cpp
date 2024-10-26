class Solution {
public:
    void recursion(vector<int> &nums, int idx, vector<int> &current_subset, vector<vector<int>> &all_subsets) {
        if(idx >= nums.size()) {
            all_subsets.push_back(current_subset);
            return;
        }

        current_subset.push_back(nums[idx]);
        recursion(nums, idx + 1, current_subset, all_subsets);
        current_subset.pop_back();
        recursion(nums, idx + 1, current_subset, all_subsets);
        
    }

    int backtracking(vector<int> &nums, int idx, int Xor) {
        if(idx >= nums.size()) {
            return Xor;
        }

        int take = backtracking(nums, idx + 1, Xor ^ nums[idx]);
        int skip = backtracking(nums, idx + 1, Xor);

        return take + skip;
    }

    int subsetXORSum(vector<int>& nums) {
        // Approach 1: by creating all subsets
        // vector<vector<int>> all_subsets;
        // vector<int> current_subsets;

        // recursion(nums, 0, current_subsets, all_subsets);

        // int ans = 0;
        // for(vector<int> &subset: all_subsets) {
        //     int Xor = 0;
            
        //     for(int &x: subset) {
        //         Xor ^= x;
        //     }

        //     ans += Xor;
        // }

        // return ans;


        // Approach 2: without storing all the subsets then finding xor
        // instead we could find xor on the fly and in both calls we retunr the sum of them

        return backtracking(nums, 0, 0);
    }
};
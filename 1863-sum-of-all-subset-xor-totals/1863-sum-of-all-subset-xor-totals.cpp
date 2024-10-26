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

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> all_subsets;
        vector<int> current_subsets;

        recursion(nums, 0, current_subsets, all_subsets);

        int ans = 0;
        for(vector<int> &subset: all_subsets) {
            int Xor = 0;
            
            for(int &x: subset) {
                Xor ^= x;
            }

            ans += Xor;
        }

        return ans;
    }
};
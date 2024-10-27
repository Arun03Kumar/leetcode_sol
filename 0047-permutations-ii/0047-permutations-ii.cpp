class Solution {
public:
    void backtracking(unordered_map<int, int> &mp, vector<int> &curr, vector<vector<int>> &ans, int &n) {
        if(curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for(auto &[num, count]: mp) {
            if(count == 0) continue;

            curr.push_back(num);
            mp[num]--;
            backtracking(mp, curr, ans, n);

            curr.pop_back();
            mp[num]++;
        }
    }

    void recursion(vector<int> &nums, int idx, vector<vector<int>> &ans) {

        if(idx >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> st;

        for(int i = idx; i < nums.size(); i++) {
            if(st.find(nums[i]) == st.end()) {
                swap(nums[i], nums[idx]);
                st.insert(nums[i]);
                recursion(nums, idx + 1, ans);

                swap(nums[i], nums[idx]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // in permutation 1 we have to take care about the number itself
        // but here we have to take care of count of the number 
        // if count of the number is greater than 0 it means we can still take that number
        // and furthur do the same processing

        // vector<vector<int>> ans;
        // vector<int> curr;

        // unordered_map<int, int> mp;
        // int n = nums.size();

        // for(int &x: nums) mp[x]++;

        // backtracking(mp, curr, ans, n);
        // return ans;


        // Approach 2: using swaps
        // if we use similar approach as in permutaion 1, then when we swap the similar elements then we get the same state multiple times and this way we will replicate the answer more than once
        // so we just have to take care that we are not swapping with same element
        // for that we could use unordered_Set

        vector<vector<int>> ans;
        recursion(nums, 0, ans);
        return ans;
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newNums(n);
        k = k % n;

        for(int i = 0; i < n; i++) {
            newNums[(i + k + n) % n] = nums[i];
        }
        nums = newNums;
    }
};
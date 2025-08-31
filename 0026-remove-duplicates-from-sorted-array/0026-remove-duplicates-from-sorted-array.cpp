class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        int prev = nums[0];

        for(int i = 0; i < n; i++) {
            if(nums[i] == prev) continue;

            prev = nums[i];
            swap(nums[++k], nums[i]);
        }

        return k + 1;
    }
};
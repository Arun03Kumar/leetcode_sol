class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int i = 0, n = nums.size();

        while(i < n - 1) {
            if(nums[i] == nums[i + 1]) {
                nums[i] = 2 * nums[i];
                nums[i + 1] = 0;
            }
            i++;
        }

        int j = 0;
        for(i = 0; i < n; i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }

        return nums;

    }
};
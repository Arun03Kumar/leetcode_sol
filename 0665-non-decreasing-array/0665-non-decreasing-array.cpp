class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int count = 1;

        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] >= nums[i]) continue;
            if(count == 0) return false; 

            if(nums[i + 1] >= (i == 0 ? INT_MIN : nums[i - 1])) {
                nums[i] = nums[i + 1];
            }
            else {
                nums[i + 1] = nums[i];
            }
            count--;
        }

        return true;
    }
};
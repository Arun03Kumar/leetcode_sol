class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = 0, j = nums.size() - 1, k = 0;
        while(k < nums.size()) {
            if(nums[k] % 2 == 0) {
                ans[i++] = nums[k++];
            }
            else {
                ans[j--] = nums[k++];
            }
        }
        return ans;

    }
};
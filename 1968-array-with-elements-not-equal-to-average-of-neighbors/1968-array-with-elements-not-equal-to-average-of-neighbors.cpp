class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(nums.size());
        int i = 0, l = 0, r = nums.size() - 1;
        while(i < nums.size()) {
            if(i % 2 == 0) {
                ans[i] = nums[l]; 
                l++;
            }
            else {
                ans[i] = nums[r];
                r--;
            }
            i++;
        }
        return ans;
    }
};
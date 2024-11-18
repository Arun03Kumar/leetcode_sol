class Solution {
public:
    void two_sum(vector<int> &nums, int idx, vector<vector<int>> &ans, int target) {
        int i = idx, j = nums.size() - 1;

        while(i < j) {
            if(nums[i] + nums[j] > target) j--;
            else if(nums[i] + nums[j] < target) i++;
            else {
                ans.push_back({-target, nums[i], nums[j]});
                while(i < j && nums[i] == nums[i + 1]) i++;
                while(i < j && nums[j] == nums[j - 1]) j--;
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        // basically for each of the numbers fo the 2 sum finding in the rest of the array.
        // for that we need to sort the array so for each element use two pointer technique to find the sum
        // when we get the answer then we can check if there are duplicate elements are present at the both pointer, we can pass over them beacuse they will give duplicate triplets.

        int n = nums.size();
        vector<vector<int>> ans;

        sort(begin(nums), end(nums));

        for(int i = 0; i < n - 2; i++) {
            // this is to filter all the repeating elements so that we don't get multiple triplets
            if(i != 0 && nums[i - 1] == nums[i]) continue;
            two_sum(nums, i + 1, ans, -nums[i]);
        }
        return ans;
    }
};
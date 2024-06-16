class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //max_number contains the maximum number that can be formed by the sum till ith position if that number is not present in the given array then we need to increase the ans, and if previous sum is 12 and current element is 10 then it means now we can form elements till 10 + 12.
        long long ans = 0, max_number = 0, i = 0;
        while(max_number < n) {
            if(i < nums.size() && max_number + 1 >= nums[i]) {
                max_number += nums[i];
                i++;
            }
            else {
                ans++;
                max_number += (max_number + 1);
            }
        }
        return ans;
    }
};
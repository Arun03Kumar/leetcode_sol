class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int l = 0, r = nums.size();

        // while(l < r) {
        //     int mid = l + (r - l) / 2;
        //     if(nums[mid] == target) {
        //         return mid;
        //     }
        //     else if(nums[mid] < target) {
        //         l = mid + 1;
        //     }
        //     else {
        //         r = mid;
        //     }
        // }
        // return l;

        auto it = lower_bound(begin(nums), end(nums), target);
        return it - begin(nums);
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] != nums[mid + 1] && mid - 1 < 0)
                return nums[mid];
            if(mid - 1 >= 0 && nums[mid] != nums[mid - 1] && mid + 1 == nums.size())
                return nums[mid];
            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];
            
            int which_side = mid;
            if(mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                which_side = mid - 1;
            }
            // else {
            //     which_side = mid;
            // }
            if(which_side % 2) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return 0;
    }
};
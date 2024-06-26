class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, ans = nums[0];
        while(low <= high) {
            // this if condition is to optimize for the case if array is completly sorted without any rotation
            if(nums[low] < nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }
            int mid = low + (high - low) / 2;
            //if arr[low] <= arr[mid] it means left side is sorted and right side is not so we eleminate left half by moving low pointer to the mid + 1. in else case it means right side is sorted so we eleminate right half. 
            if(nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // basically in binary search we eleminate one half of the array by leveraging the sorting property, but since here array is sorted in different manner hence we need to first check which half is sorted(left half or right half) by checking if arr[low] <= arr[mid] if this is true it means left half of array is sorted because left element is smaller than right one, else right part is sorted and in the sorted part we check if target is present or not if present then we do simple binary search in that else manipulate the low and high pointers in other half of array.

        // basically to follow the sorting property right side element should be greater than the left side element.
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]) {
                if(target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if(target >= nums[mid + 1] && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }                
        }
        return -1;
    }
};
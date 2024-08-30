class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;

        while(j >= 0 && nums[j] == val) j--;

        int count = 0;
        while(i < j) {
            if(nums[i] != val) count++;
            if(nums[i] == val && nums[j] != val) {
                swap(nums[i], nums[j]);
                j--;
                i++;
            }
            else if(nums[i] == val && nums[j] == val) {
                j--;
            }
            else {
                i++;
            }
            
        }

        return j + 1;
    }
};
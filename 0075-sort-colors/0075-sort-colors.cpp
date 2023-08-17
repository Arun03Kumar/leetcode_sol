class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, twos = nums.size()-1, i = 0;
        while(i < nums.size() && i <= twos) {
            if(nums[i] == 0) {
                swap(nums[zero], nums[i]);
                zero++;
                i++;
            }
            else if(nums[i] == 2) {
                swap(nums[i], nums[twos]);
                twos--;
            } else {
                i++;
            }
        }
    }
};
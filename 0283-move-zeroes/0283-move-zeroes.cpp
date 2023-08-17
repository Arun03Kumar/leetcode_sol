class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0, i = 0, j = 0;
        while(i < nums.size()) {
            if(nums[i] == 0) {
                count++;
                i++;
            } else{
                nums[j] = nums[i];
                i++;
                j++;
            }
        }
        j = nums.size() - 1;
        while(count--) {
            nums[j--] = 0;
        }
    }
};
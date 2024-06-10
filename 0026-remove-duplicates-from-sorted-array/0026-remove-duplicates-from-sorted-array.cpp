class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ansPtr = 1, current = nums[0], i = 1, count = 1;
        while(i < nums.size()) {
            if(nums[i] == current) {
                i++;
            }
            else {
                current = nums[i];
                nums[ansPtr++] = nums[i++];
                count++;
            }
        }
        return count;
    }
};
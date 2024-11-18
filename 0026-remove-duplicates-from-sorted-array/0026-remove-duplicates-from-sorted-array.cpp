class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;

        while(i < nums.size()) {
            int temp = nums[i];
            while(i < nums.size() && nums[i] == temp) i++;
            nums[j] = temp;
            j++;
        }

        return j;
    }
};
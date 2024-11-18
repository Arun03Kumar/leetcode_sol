class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;

        while(i < nums.size()) {
            int temp = nums[i];

            int count = 0;
            while(i < nums.size() && nums[i] == temp) {
                i++;
                count++;
            }

            int x = min(2, count);
            while(x--) {
                nums[j] = temp;
                j++;
            }
        }

        return j;
    }
};
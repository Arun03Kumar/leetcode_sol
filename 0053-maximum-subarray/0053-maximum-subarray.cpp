class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0, j = 0, count = nums[0], temp = 0;
        while(i < nums.size()) {
            temp += nums[i];
            count = max(temp, count);
            if(temp <= 0) {
                // j = i;
                temp = 0;
            }
            i++;
        }
        return count;
    }
};
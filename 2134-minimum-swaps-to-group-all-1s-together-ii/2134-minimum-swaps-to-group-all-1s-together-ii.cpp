class Solution {
public:
    int minSwaps(vector<int>& nums) {

        // just create a window of size all ones, means count number of ones and create window of that size.
        // now slide over this window and count number of ones in this window

        int n = nums.size();

        int count_ones = 0;
        for(int x: nums) {
            if(x == 1) count_ones++;
        }
        
        int temp_ones = 0;
        int i = 0,  j = 0;

        int ans = INT_MAX;

        while(j < 2 * nums.size()) {

            if(j - i + 1 <= count_ones) {
                if(nums[j % n] == 1) {
                    temp_ones++;
                }
            }
            else {
                if(nums[i % n] == 1) temp_ones--;

                if(nums[j % n] == 1) temp_ones++;

                i++;

                ans = min(ans, count_ones - temp_ones);

            }

            j++;

        }

        return ans;
    }
};
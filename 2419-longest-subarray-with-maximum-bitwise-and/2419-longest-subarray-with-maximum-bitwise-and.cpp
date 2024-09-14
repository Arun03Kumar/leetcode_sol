class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // if we do and of two numbers then  result will always be equal to or smaller than both number, it will never be greater than those number
        // so based on this observation we need to only find the max window in which max element of array occurs
        int ans = 0, streak = 0, max_val = 0;
        for(int &num: nums) {
            if(num > max_val) {
                max_val = num;
                streak = 0;
                ans = 0;
            }

            if(num == max_val) {
                streak++;
            }
            else {
                streak = 0;
            }

            ans = max(streak, ans);
        }

        return ans;
    }
};
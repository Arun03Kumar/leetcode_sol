class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_p = nums[0];
        int min_p = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            if(x < 0) {
                swap(max_p, min_p);
            }
            max_p = max(x, x * max_p);
            min_p = min(x, x * min_p);

            ans = max(ans, max_p);
        }

        return ans;
    }
};
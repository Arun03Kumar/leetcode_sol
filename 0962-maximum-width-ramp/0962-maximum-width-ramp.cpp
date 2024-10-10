class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // Brute force
        // int n = nums.size();
        // int ans = 0;
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(nums[j] >= nums[i]) {
        //             ans = max(ans, j - i);
        //         }
        //     }
        // }

        // return ans;

        int n = nums.size();
        vector<int> max_idx(n);
        max_idx[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            max_idx[i] = max(max_idx[i + 1], nums[i]);
        }

        int ans = 0;

        int i = 0, j = 0;

        while(j < n) {
            while(i < j && nums[i] > max_idx[j]) i++;

            ans = max(ans, j - i);
            j++;
        }

        return ans;
    }
};
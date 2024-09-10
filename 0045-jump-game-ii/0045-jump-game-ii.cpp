class Solution {
public:
    int recursion(vector<int>& nums, int idx) {
        if(idx >= nums.size() - 1) return 0;

        int temp = 10001;

        for(int i = 1; i <= nums[idx]; i++) {
            temp = min(temp, recursion(nums, idx + i));
        }
        return temp + 1;
    }

    int memoization(vector<int> &nums, int idx, vector<int> &dp) {

        if(idx >= nums.size() - 1) return 0;

        if(dp[idx] != -1) return dp[idx];

        int temp = 10001;
        for(int i = 1; i <= nums[idx]; i++) {
            temp = min(temp, memoization(nums, idx + i, dp));
        }

        return dp[idx] = (temp + 1);

    }
 
    int jump(vector<int>& nums) {
        // Approach 1: Recursion
        // int ans = recursion(nums, 0);
        // return ans;


        // Appraoch 2: Memoization
        // int n = nums.size();
        // vector<int> dp(n, -1);
        // return memoization(nums, 0, dp);


        // Approach 3: Bottom up
        // state of dp define the current jump minimum jump needed to reach that index
        // int n = nums.size();
        // vector<int> dp(n, 0);
        // dp[0] = 0;

        // for(int i = 1; i < n; i++) {

        //     for(int j = i - 1; j >= 0; j--) {
        //         if(j + nums[j] >= i) {
        //             dp[i] = min(dp[i], dp[j] + 1);
        //         }
        //     }

        // }

        // return dp[n - 1];


        // Approach 4: Optimal
        // this is like a BFS in which we can check how much level we can go
        // so we start from 0 and go maximum 
        int n = nums.size(), i = 0;
        int max_rechable = 0, last_jumped_pos = 0, ans = 0;

        while(last_jumped_pos < n - 1) {

            max_rechable = max(max_rechable, i + nums[i]);
            if(i == last_jumped_pos) {
                last_jumped_pos = max_rechable;
                ans++;
            }

            i++;

        }

        return ans;
        
    }
};
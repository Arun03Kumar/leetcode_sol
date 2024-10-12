class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // if we treat 0 as -1 then we need to find the subarray with target sum 0, now this problem is similar to leetcode 560
        // so we find the current sum till index i and we try to find if we have already seen this current sum in the previous array, if yes it means from that index to till this index sum of elements would be zero, because then only we can get the same sum
        // then find the window size and update the answer if it is max than prev
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;

        int curr_sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) curr_sum -= 1;
            else curr_sum += 1;

            if(mp.find(curr_sum) == mp.end()) {
                mp[curr_sum] = i;
            }
            else {
                int window_size = i - mp[curr_sum];
                ans = max(ans, window_size);
            }
        }

        return ans;
    }
};
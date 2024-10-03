class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // BruteForce

        // int ans = INT_MAX;
        // long long sum = 0;
        // for(int &x: nums) sum += x;
        // if(sum % p == 0) return 0;
        // for(int i = 0; i < nums.size(); i++) {
        //     long long temp = 0;
        //     for(int j = i; j < nums.size(); j++) {
        //         if(i == 0 && j == nums.size() - 1) continue;
        //         temp += nums[j];

        //         if((sum - temp) % p == 0) ans = min(j - i + 1, ans);
        //     }
        // }

        // return ans == INT_MAX ? -1 : ans;

        int n = nums.size();
        int sum = 0;
        for(int &x: nums) {
            sum = (sum + x) % p;
        } 

        int target = sum % p;

        if(target == 0) return 0;

        unordered_map<int, int> mp;

        int curr_sum = 0;
        mp[0] = -1;
        int ans = n;

        for(int i = 0; i < n; i++) {
            curr_sum = (curr_sum + nums[i]) % p;
            int remain = (curr_sum - target + p) % p;

            if(mp.find(remain) != mp.end()) {
                ans = min(ans, i - mp[remain]);
            }

            mp[curr_sum] = i;
        }

        return ans == n ? -1 : ans;

    }
};
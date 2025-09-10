class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int curr_sum = 0, ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            curr_sum += nums[i];
            int rem = ((curr_sum % k) + k) % k;
            if(mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            mp[rem]++;
        }
        return ans;
    }
};
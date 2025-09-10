class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int curr_sum = 0, ans = 0;
        mp[0] = -1;

        for(int i = 0; i < nums.size(); i++) {
            curr_sum += (nums[i] == 0) ? -1 : 1;
            if(mp.find(curr_sum) != mp.end()) {
                int x = mp[curr_sum];
                ans = max(ans, i - x);
            }

            if(mp.find(curr_sum) == mp.end()) {
                mp[curr_sum] = i;
            }
        }

        return ans;
    }
};
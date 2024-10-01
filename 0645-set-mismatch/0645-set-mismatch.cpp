class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // Approach 1: using map
        unordered_map<int, int> mp;
        for(int &x: nums) {
            mp[x]++;
        }

        vector<int> ans(2);

        for(int i = 1; i <= nums.size(); i++) {
            if(mp.find(i) == mp.end()) {
                ans[1] = i;
            }
            else if(mp[i] > 1) {
                ans[0] = i;
            }
        }

        return ans;
    }
};
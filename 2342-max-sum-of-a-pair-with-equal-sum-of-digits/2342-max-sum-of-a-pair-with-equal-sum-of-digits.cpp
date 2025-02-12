class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int ans = -1;

        for(int i = 0; i < n; i++) {
            int temp = 0;
            int x = nums[i];
            while(x) {
                temp += x % 10;
                x /= 10;
            }

            // cout << temp << " ";
            
            if(mp.find(temp) != mp.end()) {
                ans = max(ans, mp[temp] + nums[i]);
                mp[temp] = max(mp[temp], nums[i]);
            }
            else {
                mp[temp] = nums[i];
            }
        }

        return ans;
    }
};
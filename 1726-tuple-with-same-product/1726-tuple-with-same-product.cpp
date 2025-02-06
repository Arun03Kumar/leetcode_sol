class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int mult = nums[i] * nums[j];
                freq[mult]++;
            }
        }

        int ans = 0;
        for(auto &[key, val]: freq) {
            ans += (val * (val - 1) / 2);
        }

        return ans * 8;
    }
};
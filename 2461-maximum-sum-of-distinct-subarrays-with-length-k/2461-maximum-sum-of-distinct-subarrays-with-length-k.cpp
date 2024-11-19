class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        unordered_set<int> duplicates;

        bool is_duplicate = false;
        long long ans = 0;
        int n = nums.size();

        for(int i = 0; i < k; i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1) {
                is_duplicate = true;
                duplicates.insert(nums[i]);
            }
            if(!is_duplicate) ans += nums[i];
        }
        
        if(is_duplicate) ans = 0;

        for(int i = 0; i < n - k + 1; i++) {
            if(duplicates.empty()) {
                long long temp = 0;
                for(int j = i; j < i + k; j++) {
                    temp += nums[j];
                }
                cout << temp << " ";
                ans = max(ans, temp);
            }
            mp[nums[i]]--;
            if(mp[nums[i]] == 1) duplicates.erase(nums[i]);
            if(i + k < n) mp[nums[i + k]]++;
            if(i + k < n && mp[nums[i + k]] > 1) duplicates.insert(nums[i + k]);
        }

        return ans;
    }
};
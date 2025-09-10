class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int curr_sum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;  // important base case
        
        for(int num : nums) {
            curr_sum += num;
            
            // if (curr_sum - k) appeared before, add its count
            if(mp.find(curr_sum - k) != mp.end()) {
                ans += mp[curr_sum - k];
            }
            
            // always update the frequency of curr_sum
            mp[curr_sum]++;
        }
        
        return ans;
    }
};
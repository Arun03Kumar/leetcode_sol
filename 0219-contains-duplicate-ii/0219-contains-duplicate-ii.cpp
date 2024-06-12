class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0, r = k + 1, p;
        // if(nums.size() == 1 || nums.size() == 0)
        //     return false;
        if(k < nums.size()) p = k;
        else p = nums.size();
        map<int, int> mp;
        for(int i = 0; i <= p; i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1)
                return true;
        }

        while(r < nums.size()) {
            mp[nums[l++]]--;
            mp[nums[r]]++;
            if(mp[nums[r]] > 1)
                return true;
            else
                r++;
        }
        return false;
    }
};
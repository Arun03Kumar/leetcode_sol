class Solution {
public:
    int minOperations(vector<int>& nums) {
        // follow a greedy approach 
        // count the freq of each element
        // if freq is not divisible by 3 then decrease it by 2 until it became divisble by the
        // keep the counter count and add into the ans
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int &x: nums) mp[x]++;

        int ans = 0;
        for(auto [key, val]: mp) {
            if(val == 1) return -1;
            int count = 0;
            while(val % 3 != 0) {
                count++;
                val -= 2;
            }

            ans += count;
            ans += val / 3;
        }

        return ans;
    }
};
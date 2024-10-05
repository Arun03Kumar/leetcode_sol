class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // if m % p == k then (m + p) % p will also be k, it is true for all m, p, k
        // so in this senario what we will do we will maintain a map in which we store the remainder of sum till index i
        // and if we find any module already present in the map then it means we add something in our sum which is multiple of k
        // so we just have to check for the indexes
        // one special case to be taken care for 0
        // so to tackle this store 0 initially in the map

        int n = nums.size();
        unordered_map<int, int> mp; // stores <remainder, index>
        mp[0] = -1;

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;

            if(mp.find(rem) != mp.end()) {
                int size = i - mp[rem];
                if(size >= 2) return true;
            }
            else {
                mp[rem] = i;
            }
        }

        return false;
    }
};
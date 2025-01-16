class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        unordered_map<int, long long> mp;

        for(int &x: nums1) mp[x] += n;        
        for(int &x: nums2) mp[x] += m;   

        int ans = 0;
        for(auto &[key, val]: mp) {
            if(val % 2 != 0) {
                ans ^= key;
            }
        }     

        return ans;
    }
};
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;

        for(int x: nums1) mp1[x]++;
        for(int x: nums2) mp2[x]++;

        int ans1 = 0, ans2 = 0;
        for(int x: nums1) {
            if(mp2.find(x) != mp2.end()) {
                ans1++;
            }
        }

        for(int x: nums2) {
            if(mp1.find(x) != mp1.end()) {
                ans2++;
            }
        }

        return {ans1, ans2};
    }
};
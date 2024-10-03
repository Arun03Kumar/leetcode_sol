class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> mp1, mp2;

        for(int &x: nums1) mp1.insert(x);
        for(int &x: nums2) mp2.insert(x);

        vector<vector<int>> ans(2);

        for(auto &x: mp1) {
            if(mp2.find(x) == mp2.end()) {
                ans[0].push_back(x);
            }
        }

        for(auto &x: mp2) {
            if(mp1.find(x) == mp1.end()) {
                ans[1].push_back(x);
            }
        }

        return ans;
    }
};
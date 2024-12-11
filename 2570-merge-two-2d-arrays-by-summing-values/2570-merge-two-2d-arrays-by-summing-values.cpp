class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> ans;

        while(i < m && j < n) {
            if(nums1[i][0] == nums2[j][0]) {
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            else if(nums1[i][0] < nums2[j][0]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m) {
            ans.push_back(nums1[i++]);
        }

        while(j < n) {
            ans.push_back(nums2[j++]);
        }

        return ans;
    }
};
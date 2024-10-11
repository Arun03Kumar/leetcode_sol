class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // key point is check the freq of current element if it is equal to the size of the ans array it means we have to create a new array
        // and freq count can be used as the row index to insert the element

        int n = nums.size();

        vector<vector<int>> ans;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            int freq = mp[nums[i]];
            // cout << freq << " ";
            if(freq == ans.size()) {
                ans.push_back({});
            }

            ans[freq].push_back(nums[i]);
            mp[nums[i]]++;
        }

        return ans;

    }
};
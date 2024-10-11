class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // just sort the array and make pairs of 3
        // check the difference between largest and smallest integer in the pair of 3, if it is greater than k then it means it won't be able to make pairs with any interger above, hence return empty array

        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;

        for(int i = 0; i < n; i += 3) {
            int n1 = nums[i];
            int n2 = nums[i + 1];
            int n3 = nums[i + 2];

            if(n3 - n1 > k) return {};

            ans.push_back({n1, n2, n3});
        }

        return ans;
    }
};
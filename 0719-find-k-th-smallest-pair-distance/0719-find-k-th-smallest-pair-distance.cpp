class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        // Approach 1: create a distance array where index shows the differece between any two values which give the difference as index.
        // for all pairs add them in to this array

        int n = nums.size();
        int max_el = *max_element(begin(nums), end(nums));

        vector<int> abs_diff(max_el + 1, 0);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int diff = abs(nums[i] - nums[j]);
                abs_diff[diff]++;
            }
        }

        for(int i = 0; i < abs_diff.size(); i++) {
            k -= abs_diff[i];
            if(k <= 0) {
                return i;
            }
        }

        return -1;
    }
};
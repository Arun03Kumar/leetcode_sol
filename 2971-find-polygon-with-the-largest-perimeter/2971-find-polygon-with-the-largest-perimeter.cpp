class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for(int i = n - 1; i >= 2; i--) {
            long long  other_sides_sum = prefix[i - 1];
            int size_of_longest_side = nums[i];

            if(other_sides_sum > size_of_longest_side) {
                return prefix[i];
            }
        }

        return -1;
    }
};
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int sum = accumulate(begin(nums), end(nums), 0);
        int max_bags = nums.size() + maxOperations;

        return sum / max_bags;
    }
};
class Solution {
public:
    int solve(vector<int> &nums) {
        int n = nums.size();
        int i = n - 1;

        while(i--) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] >= nums[j]) continue;
                while(i >= 0 && j < n && nums[i] < nums[j]) j++;
                swap(nums[i], nums[j - 1]);
                reverse(begin(nums) + i + 1, end(nums));
                return 1;
            }
        }
        return 0;
    }

    int nextGreaterElement(int n) {
        vector<int> nums;
        while(n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(begin(nums), end(nums));
        int x = solve(nums);
        if(!x) return -1;
        long long ans = 0, mul = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans += nums[i] * mul;
            if(ans > INT_MAX) return -1;
            mul *= 10;
        }

        return (int)ans;
    }
};

// 56469
// 56496
// 56649
// 56694
// 56946
// 56964
// 59466


class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int N = *max_element(begin(nums), end(nums)); 
        vector<int> divisor_count(N + 1, 0);
        vector<long long> divisior_sum(N + 1, 0);

        for(int i = 1; i <= N; i++) {
            for(int j = i; j <= N; j += i) {
                divisor_count[j]++;
                divisior_sum[j] += i;
            }
        }

        int ans = 0;
        for(int &x: nums) {
            if(divisor_count[x] == 4) {
                ans += divisior_sum[x];
            }
        }

        return static_cast<int>(ans);
    }
};
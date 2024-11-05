class Solution {
public:
    long long gcd(int a, int b) {
        return __gcd(a, b);
    }

    long long lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_gcd(n + 1, 0);
        vector<int> suffix_gcd(n + 1, 0);
        vector<int> prefix_lcm(n + 1, 1);
        vector<int> suffix_lcm(n + 1, 1);

        for(int i = 0; i < n; i++) {
            prefix_gcd[i + 1] = gcd(prefix_gcd[i], nums[i]);
        }

        for(int i = n - 1; i >= 0; i--) {
            suffix_gcd[i] = gcd(suffix_gcd[i + 1], nums[i]);
        }

        for(int i = 0; i < n; i++) {
            prefix_lcm[i + 1] = lcm(prefix_lcm[i], nums[i]);
        }

        for(int i = n - 1; i >= 0; i--) {
            suffix_lcm[i] = lcm(suffix_lcm[i + 1], nums[i]);
        }

        for(int i = 0; i <= n; i++) {
            cout << prefix_gcd[i] << " " << suffix_gcd[i] << " " << prefix_lcm[i] << " " << suffix_lcm[i] << endl;
        }

        long long ans = prefix_gcd[n] * prefix_lcm[n];

        for(int i = 0; i < n; i++) {
            int gcd_left = prefix_gcd[i];
            int gcd_right = suffix_gcd[i + 1];
            int lcm_left = prefix_lcm[i];
            int lcm_right = suffix_lcm[i + 1];

            int total_gcd = gcd(gcd_left, gcd_right);
            int total_lcm = lcm(lcm_left, lcm_right);

            long long total = total_gcd * total_lcm;
            if(total > ans) ans = total;
            // ans = max(ans, total_gcd * total_lcm);
        }

        return ans;
    }
};

class Solution {
public:
    int gcd(int a, int b) {
        return std::gcd(a, b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            __int128 prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = gcd(g, nums[j]);
                
                // Calculate LCM safely
                l = (l / gcd((int)l, nums[j])) * nums[j];

                if(prod > 25200) break;

                if (prod == (__int128)g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    int m = 1337;

    int bin_exp(int a, int b) {
        int ans = 1;
        while(b > 0) {
            if(b & 1) ans = ans * a % m;
            a = a * a % m;
            b >>= 1;
        }

        return ans;
    }

    int superPow(int a, vector<int>& b) {
        // 5^245 can be written as 5^200 + 5^40 + 5^1
        // 5^40 can be written as    5^(10*4) => 5^10 * 5^4
        // 5^100 can be written as  5^(100*2) => 5^100 * 5^2
        // so what we are doing we are just increasing the power of 10 each time and then finding power of b[i]
        int ans = 1;

        for(int i = b.size() - 1; i >= 0; i--) {
            ans = ans * bin_exp(a, b[i]) % m;
            a = bin_exp(a, 10);
        }

        return ans;
    }
};
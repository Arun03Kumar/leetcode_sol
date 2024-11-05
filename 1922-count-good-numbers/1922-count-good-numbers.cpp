class Solution {
public:
    const int M = 1e9 + 7;
    int bin_exp(long long x, long long num) {
        int res = 1;
        while(num != 0) {
            if(num & 1) {
                res = (res * x) % M;
            }
            x = (x * x) % M;
            num >>= 1;
        }

        return res % M;
    }

    int countGoodNumbers(long long n) {
        long long half = n / 2;
        long long pow_5, pow_4;
        pow_5 = pow_4 = half;
        if(n & 1) {
            pow_5 = half + 1;
        }
        
        int a = bin_exp(5, pow_5);
        int b = bin_exp(4, pow_4);

        return (a % M) * 1LL * (b % M) % M;
    }
};
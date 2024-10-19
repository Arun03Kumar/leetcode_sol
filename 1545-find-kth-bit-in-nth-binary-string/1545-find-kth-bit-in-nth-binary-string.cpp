class Solution {
public:
    char findKthBit(int n, int k) {
        // instead of first creating the string then finding the required character 
        // we can have some observations
        // 1. middile element for Si will always be 1
        // 2. if k  is less than the half of length of Si, then it means it will be equal to the kth character of S(i - 1)
        // 3. if k is larger than half of length of Si then it means it will be equal to the reverse of the S(i - 1) string but also invert those bits 
        // and the position of kth bit will be also at (n - k - 1)th position in the reversed and inverted string
        // 4. the length of Sn(th) string would be 2*length(S(n - 1)) + 1
        // means if n = 4 then length of string will be 2*(len(S3)) + 1 and len of S3 = 7 so length of S4 would be 2*7+1 = 15
        // so for n, we can find the len as (2^n) - 1;  -> 2^4-1 = 16-1 = 15

        if(n == 1) return '0';

        int length = (1 << n) - 1; // (pow(2, n) - 1)
        int half_of_len = ceil(length / 2.0);

        if(k < half_of_len) return findKthBit(n - 1, k); // if k is less than half then it will be same as the kth bit for n-1th string
        else if(k == half_of_len) return '1';
        else {
            char ch = findKthBit(n - 1, length - (k - 1));
            if(ch == '0') return '1';
            else return '0';
        }
    }
};
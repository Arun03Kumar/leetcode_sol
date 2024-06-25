class Solution {
public:
    int numberOfChild(int n, int k) {
        if(k < n) return k;
        else {
            if((k / (n - 1)) % 2) {
                return k % (n - 1);
            }
            else {
                return (k + 2) % n;
            }
        }
    }
};
class Solution {
public:
    int kthGrammar(int n, int k) {
        int l = 0, r = pow(2, n - 1), current = 0;
        for(int i = 0; i < n - 1; i++) {
            int mid = (l + r) / 2;
            if(k <= mid) {
                r = mid;
            }
            else {
                l = mid + 1;
                current = current ? 0 : 1;
            }
        }
        return current;
    }
};
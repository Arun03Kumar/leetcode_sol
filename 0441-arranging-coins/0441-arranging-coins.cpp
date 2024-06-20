class Solution {
public:
    long long natural_sum(int x) {
        return (x) * 1LL * (x + 1) * 1LL / 2;
    }
    int arrangeCoins(int n) {
     int low = 1, high = n, ans = 0;
     while(low <= high) {
        int mid = low + (high - low) / 2;
        long long sum = natural_sum(mid);
        if(sum > n) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
            ans = max(mid, ans);
        }
     } 
     return ans;  
    }
};
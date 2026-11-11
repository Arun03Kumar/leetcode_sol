class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans;

        if(costBoth > cost1 && costBoth > cost2) {
            if(cost1 + cost2 < costBoth) {
                ans = 1LL * need1 * cost1  + 1LL * need2 * cost2;
            }
            else {
                // if(cost1 < cost2) {
                //     if(need1 > need2) {
                //         ans = need2 * costBoth + (need1 - need2) * cost1;
                //     }
                //     else {
                //         ans = need2 * costBoth;
                //     }
                // }
                // else {
                //     if(need2 > need1) {
                //         ans = need1 * costBoth * 1LL + (need2 - need1) * cost2 * 1LL;
                //     }
                //     else {
                //         ans = need1 * costBoth * 1LL;
                //     }
                // }
                // min(need1, need2) * costBoth + max(need1, need2) - min(need1, need2) * m(cost1)
                int mn = min(need1, need2);
                int mx = max(need1, need2);

                ans = 1LL * mn * costBoth;
                if(need1 >= need2) {
                    ans += (mx - mn) * 1LL * cost1;
                }
                else {
                    ans += (mx - mn) * 1LL * cost2;
                }


            }
        }
        else if(costBoth <= cost1 && costBoth <= cost2) {
            ans = costBoth * 1LL * max(need1, need2);
        }
        else {
            if(cost1 > costBoth) {
                if(need1 > need2) {
                    ans = 1LL * costBoth * need1;
                }
                else {
                    ans = 1LL * need1 * costBoth + 1LL * (need2 - need1) * cost2;
                }
            }
            else if(cost2 > costBoth) {
                if(need2 > need1) {
                    ans = 1LL * costBoth * need2;
                }
                else {
                    ans = 1LL * need2 * costBoth + 1LL * (need1 - need2) * cost1;
                }
            }
        }

        return ans;
    }
};
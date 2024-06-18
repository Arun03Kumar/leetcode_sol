class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int> > pro_dif;
        for(int i = 0; i < profit.size(); i++) {
            pro_dif.push_back(make_pair(difficulty[i], profit[i]));
        }
        sort(pro_dif.begin(), pro_dif.end());
        sort(worker.begin(), worker.end());
        int max_profit = 0, ans = 0, l = 0, r = 0;
        while(l < worker.size()) {
            if(r < pro_dif.size() && worker[l] >= pro_dif[r].first) {
                max_profit = max(max_profit, pro_dif[r].second);
                r++;
            }
            else {
                ans += max_profit;
                l++;
            }
        }
        return ans;
    }
};
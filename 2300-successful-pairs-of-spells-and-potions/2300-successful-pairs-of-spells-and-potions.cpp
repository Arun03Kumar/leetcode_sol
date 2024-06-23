class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size());
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++) {
            int low = 0, high = potions.size() - 1, tmp = potions.size();
            while(low <= high) {
                int mid = low + high / 2;
                if(potions[mid] * spells[i] >= success) {
                    tmp = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            ans[i] = potions.size() - tmp;
        }
        return ans;
    }
};
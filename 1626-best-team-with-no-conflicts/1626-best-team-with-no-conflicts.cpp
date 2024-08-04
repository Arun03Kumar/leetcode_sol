class Solution {
public:
    int recursion(vector<int>& scores, vector<int>& ages, int idx, int prev) {
        if(idx >= scores.size()) return 0;

        int take = 0;
        if(prev == -1 || (ages[idx] >= ages[prev]) || (ages[idx] < ages[prev] && scores[idx] <= scores[prev])) {
            take = scores[idx] + recursion(scores, ages, idx + 1, idx);
        }

        int skip = recursion(scores, ages, idx + 1, prev);

        return max(take, skip);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        return recursion(scores, ages, 0, -1);
    }
};
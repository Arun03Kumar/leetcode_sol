class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // sort in descending order so that we can process high cost cuts first, because if we do it later then we have to do it for multiple cuts which will cost us more.

        // if we cut horizontally then we have to multiply it with number of vertical peices and vice versa.

        int x = horizontalCut.size();
        int y = verticalCut.size();

        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());

        int i = 0, j = 0;

        int horizontal_peices = 1, vertical_peices = 1;
        long long ans = 0;

        while(i < x && j < y) {
            if(horizontalCut[i] >= verticalCut[j]) {
                ans += horizontalCut[i] * vertical_peices;
                horizontal_peices++;
                i++;
            }
            else {
                ans += verticalCut[j] * horizontal_peices;
                vertical_peices++;
                j++;
            }
        }

        while(i < x) {
            ans += horizontalCut[i] * vertical_peices;
            horizontal_peices++;
            i++;
        }

        while(j < y) {
            ans += verticalCut[j] * horizontal_peices;
            vertical_peices++;
            j++;
        }

        return ans;
    }
};
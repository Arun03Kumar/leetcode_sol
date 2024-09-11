class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // take left_sum and right_sum which stores the sum of elements in a window of k, now decrease the window for left_sum and increase the window for right_sum
        int n = cardPoints.size();

        int left_sum = 0;
        for(int i = 0; i < k; i++) left_sum += cardPoints[i];

        int right_sum = 0;
        int max_sum = left_sum;

        int right_idx = n - 1;

        for(int i = k - 1; i >= 0; i--) {
            left_sum -= cardPoints[i];
            right_sum += cardPoints[right_idx];
            right_idx--;

            max_sum = max(max_sum, left_sum + right_sum);
        }

        return max_sum;
    }
};
class Solution {
public:
    int WIDTH;
    int recursion(vector<vector<int>>& books, int rem_width, int idx, int curr_height) {
        if(idx >= books.size()) return curr_height;

        int book_height = books[idx][1];
        int book_width = books[idx][0];

        int keep = INT_MAX;
        if(book_width <= rem_width) {
            keep = recursion(books, rem_width - book_width, idx + 1, max(curr_height, book_height));
        }

        int skip = INT_MAX;
        skip = curr_height + recursion(books, WIDTH - book_width, idx + 1, book_height);

        return min(keep, skip);
    }

    int memoization(vector<vector<int>>& books, vector<vector<int>>& dp, int idx, int rem_width, int max_curr_height) {

        if(idx >= books.size()) return max_curr_height;

        if(dp[idx][rem_width] != -1) return dp[idx][rem_width];

        int book_width = books[idx][0];
        int book_height = books[idx][1];

        int keep = INT_MAX;
        if(book_width <= rem_width) {
            keep = memoization(books, dp, idx + 1, rem_width - book_width, max(max_curr_height, book_height));
        }

        int skip = max_curr_height + memoization(books, dp, idx + 1, WIDTH - book_width, book_height);

        return dp[idx][rem_width] = min(keep, skip);

    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        WIDTH = shelfWidth;

        // Approach 1: recursion
        // for each book we have two options to keep in the current shelf or keep in the next shelf, if we want to keep in the next row then we have to start with complete width
        // return recursion(books, shelfWidth, 0, 0);

        // Approach 2: memoization

        int n = books.size();
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return memoization(books, dp, 0, shelfWidth, 0);
    }
};
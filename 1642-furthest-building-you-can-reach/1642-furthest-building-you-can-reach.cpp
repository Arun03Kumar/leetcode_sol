class Solution {
public:
    int recursion(vector<int> &arr, int b, int l, int idx) {
        if(idx == arr.size() - 1) return 0;

        if(arr[idx + 1] <= arr[idx]) {
            return 1 + recursion(arr, b, l, idx + 1);
        }
        else {
            int by_brick = 0;
            int by_ladder = 0;

            int diff = arr[idx + 1] - arr[idx];

            if(b >= diff) {
                by_brick = 1 + recursion(arr, b - diff, l, idx + 1);
            }

            if(l > 0) {
                by_ladder = 1 + recursion(arr, b, l - 1, idx + 1);
            }

            return max(by_brick, by_ladder);
        }

        return -1;
    }

    int memoization(vector<int> &arr, int b, int l, int idx, vector<vector<int>> &dp) {
        if(idx == arr.size() - 1) return 0;

        if(dp[b][l] != -1) return dp[b][l];

        if(arr[idx + 1] <= arr[idx]) {
            return dp[b][l] = 1 + memoization(arr, b, l, idx + 1, dp);
        }
        else {
            int by_brick = 0;
            int by_ladder = 0;

            int diff = arr[idx + 1] - arr[idx];

            if(b >= diff) {
                by_brick = 1 + memoization(arr, b - diff, l, idx + 1, dp);
            }

            if(l > 0) {
                by_ladder = 1 + memoization(arr, b, l - 1, idx + 1, dp);
            }

            return dp[b][l] = max(by_brick, by_ladder);
        }

    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // Approach 1: Recursion
        // return recursion(heights, bricks, ladders, 0);


        // Approach 2: memoization (will give memory limit excedded since constraints are large)
        // vector<vector<int>> dp(bricks + 1, vector<int>(ladders + 1, -1));
        // return memoization(heights, bricks, ladders, 0, dp);


        // Approach 3: Lazy Greedy
        // let's say we are at a position where we have exhausted all the bricks but we still have a ladder
        // so what we can do we can go back where we have used the largest amount of bricks, there we can use one ladder with this in we can revive that much of bricks
        // we can track the largest amount of bricks using priority queue

        // so if number of bricks is greater than current requirement then we can use those brocks and push them in pq
        // if not then we can use ladders but before using ladders we can check that if we have used number of bricks larger than current requirement
        // so in that case we can use ladder there and increase the count of bricks
        // if not then use the ladder here

        // if pq is empty means we have to use the ladder

        int n = heights.size();
        priority_queue<int, vector<int>> pq;

        int i = 0;
        for(; i < n - 1; i++) {

            if(heights[i + 1] <= heights[i]) continue;

            int diff = heights[i + 1] - heights[i];
            // if bricks are availabe then use them and push into pq
            if(bricks >= diff) {
                bricks -= diff;
                pq.push(diff);
            }
            else if(ladders > 0) {

                // if we have extra ladder and not much bricks so we can check if in past we have used large amount of bricks if yes then retrive those and use ladder there
                if(!pq.empty()) {
                    int max_bricks_past = pq.top();
                    if(max_bricks_past > diff) {
                        bricks += max_bricks_past; // add past bricks
                        ladders--; // use ladder there

                        pq.pop();

                        bricks -= diff; // use bricks at current index
                        pq.push(diff);
                    }
                    else {
                        ladders--;
                    }
                }
                else {
                    ladders--;
                }
            }
            else { // if ladders is less than 1 and we dont have enough bricks
                break;
            }
        }

        return i;
    }
};
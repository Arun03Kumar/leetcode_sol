class Solution {
public:
    // long long cost[100001];
    long long compute_op(vector<int> &nums, int s, int e) {
        vector<int> temp(nums.begin() + s, nums.begin() + e + 1);
        sort(begin(temp), end(temp));
        int median = temp[temp.size() / 2];

        long long cnt = 0;
        for(int x: temp) {
            cnt += abs((long long)x - median);
        }

        // cout << median 
        return cnt;
    }

    int rec(auto pq, int k) {
        // this is greedy and it won't work here, also base condition is not there
        int ans = pq.top()[0];
        int l = pq.top()[1], r = pq.top()[2];

        int n_k = k;

        pq.pop();

        auto new_pq = pq;

        while(!pq.empty() && k - 1 > 0) {
            vector<int> t = pq.top();
            if(t[2] < l || t[1] > r) {
                ans += t[0];
                l = t[1];
                r = t[2];
                k--;
            }
            pq.pop();
            // cout << t[0] << " " << t[1] << " " << t[2] << endl;
            // pq.pop();
        }

        if(k > 0) {
            new_pq.pop();
            return rec(new_pq, n_k);
        }

        return ans;
    }

    vector<vector<long long>> dp;
    vector<long long> cost;
    long long recursion(vector<vector<int>> &arr, int idx, int k, int l, int r) {
        if(k == 0) return 0;
        if(idx == arr.size()) {
            return LLONG_MAX / 2;
        }

        if(dp[idx][k] != -1) return dp[idx][k];

        int val = arr[idx][0];
        int left = arr[idx][1];
        int right = arr[idx][2];

        long long exc = recursion(arr, idx + 1, k, l, r);

        long long inc = LLONG_MAX / 2;
        if(right < l || left > r) {
            inc = val + recursion(arr, idx + 1, k - 1, left, right);
        }
        dp[idx][k] = min(inc, exc);
        return dp[idx][k];
    }

    long long memo(vector<long long> &arr, int idx, int k, int x) {
        if(k == 0) return 0;
        if(idx >= arr.size()) {
            return LLONG_MAX / 2;
        }

        if(dp[idx][k] != -1) return dp[idx][k];

        long long val = arr[idx];

        long long exc = memo(arr, idx + 1, k, x);
        long long inc = val + memo(arr, idx + x, k - 1, x);

        dp[idx][k] = min(inc, exc);
        return dp[idx][k];
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        // int i = 0, j = x - 1;
        // vector<long long> arr;
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // while(j < nums.size()) {
        //     long long op = compute_op(nums, i, j);
        //     // pq.push({op, i, j});
        //     arr.push_back(op);
        //     i++;
        //     j++;
        // }

        cost.resize(nums.size() - x + 1);

        multiset<long long> left, right;
        long long left_sum = 0, right_sum = 0;

        int i = 0, j = 0;

        while(j < nums.size()) {
            if(left.size() <= right.size()) {
                left.insert(nums[j]);
                left_sum += nums[j];
            }
            else {
                right.insert(nums[j]);
                right_sum += nums[j];
            }

            // balancing or adjustment
            if(!left.empty() && !right.empty()) {
                int max_left = *left.rbegin();
                int right_min = *right.begin();

                if(right_min < max_left) {
                    left.erase(left.find(max_left));
                    right.erase(right.find(right_min));

                    left.insert(right_min);
                    right.insert(max_left);

                    left_sum = left_sum - max_left + right_min;
                    right_sum = right_sum - right_min + max_left;
                }
            }

            if(j - i + 1 == x) {
                long long median = *left.rbegin();
                long long left_size = left.size();
                long long right_size = right.size();

                long long left_size_cost =  left_size * median - left_sum;
                long long right_size_cost =  right_sum - right_size * median;

                cost[i] = left_size_cost + right_size_cost;

                if(left.find(nums[i]) != left.end()) {
                    left.erase(left.find(nums[i]));
                    left_sum -= nums[i];
                }
                else {
                    right.erase(right.find(nums[i]));
                    right_sum -= nums[i];
                }

                i++;
            }

            j++;
        }

        dp.resize(cost.size() + 1, vector<long long>(k + 1, -1));

        // int ans = rec(pq, k);
        // this is okay but since l and r are also there we need a bigger dp array, but since x is constant and using idx only we can find the interval
        // int ans = recursion(arr, 0, k, INT_MAX, INT_MAX);
        long long ans = memo(cost, 0, k, x);

        

        return ans;
    }
};
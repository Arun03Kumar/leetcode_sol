class Solution {
public:
    typedef pair<int, int> P;
    int M = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        // Approach 1: Brute force

        // vector<int> all_sum;

        // for(int i = 0; i < n; i++) {
        //     int temp_sum = 0;
        //     for(int j = i; j < n; j++) {
        //         temp_sum += nums[j];
        //         all_sum.push_back(temp_sum);
        //     }
        // }

        // sort(all_sum.begin(), all_sum.end());

        // int ans = 0;
        // for(int i = left - 1; i <= right - 1; i++) {
        //     ans += all_sum[i];
        // }

        // return ans;


        // Approach 2: Using Heap
        // we can use heap to find out the sum of all subarray in increasing or decreasing order using min or maxheap.
        // initially each element of given array are also considered as a subarray and they will be pushed into the min heap.
        // now at each iteration they will be expanding their sum 
        // in heap we store sum and index till current index.

        priority_queue<P, vector<P>, greater<P>> pq;

        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        int ans = 0;

        for(int i = 1; i <= right; i++) {

            auto top = pq.top();
            pq.pop();

            int sum = top.first;
            int idx = top.second;

            if(i >= left) {
                ans = (ans + sum) % M;
            }

            if(idx + 1 < n) {
                pq.push({sum + nums[idx + 1], idx + 1});
            }

        }

        return ans;
        
    }
};
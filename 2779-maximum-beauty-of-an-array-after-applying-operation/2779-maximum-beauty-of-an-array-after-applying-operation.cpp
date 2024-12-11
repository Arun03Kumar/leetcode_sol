class Solution {
public:
    int binary_search(vector<int> &nums, int k, int idx) {
        int l = 0, r = nums.size() - 1;
        int ans = idx;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] <= nums[idx] + 2 * k) {
                l = mid + 1;
                ans = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }

    int maximumBeauty(vector<int>& nums, int k) {
        // Approach 1: 
        // compute the range or interval by subtracting and adding k, and form an array of pairs
        // now we have to just fing the longest overlapping interval
        // to find the longest overlapping interval we first need to sort the array based in first element of the interval
        // then we have to check if two intervals are ovverlapping by:
        // (a, b) and (c, d) if b < c then they are not overlapping
        // so we need to maintain a queue or deque so that we can compare the current pair with the starting one because it may possible that current pair is overlapped with the previous one but not with those who are push initially in the queue

        // int n = nums.size();
        // vector<pair<int, int>> range;

        // for(int &x: nums) {
        //     range.push_back({x - k, x + k});
        // }

        // sort(begin(range), end(range));
        // int ans = 1;

        // deque<pair<int, int>> deq;
        // for(pair<int, int> &p: range) {
        //     while(!deq.empty() && deq.front().second < p.first) {
        //         deq.pop_front();
        //     }

        //     deq.push_back(p);
        //     ans = max(ans, (int)deq.size());
        // }
        // return ans;



        // Approach 2: Binary Search
        int n = nums.size();
        sort(begin(nums), end(nums));
        int ans = 1;

        for(int i = 0; i < n; i++) {
            int idx = binary_search(nums, k, i);
            ans = max(ans, idx - i + 1);
        }

        return ans;
    }
};
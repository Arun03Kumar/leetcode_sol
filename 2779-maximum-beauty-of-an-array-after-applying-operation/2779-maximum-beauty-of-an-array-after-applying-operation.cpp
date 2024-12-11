class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // Approach 1: 
        // compute the range or interval by subtracting and adding k, and form an array of pairs
        // now we have to just fing the longest overlapping interval
        // to find the longest overlapping interval we first need to sort the array based in first element of the interval
        // then we have to check if two intervals are ovverlapping by:
        // (a, b) and (c, d) if b < c then they are not overlapping
        // so we need to maintain a queue or deque so that we can compare the current pair with the starting one because it may possible that current pair is overlapped with the previous one but not with those who are push initially in the queue

        int n = nums.size();
        vector<pair<int, int>> range;

        for(int &x: nums) {
            range.push_back({x - k, x + k});
        }

        sort(begin(range), end(range));
        int ans = 1;

        deque<pair<int, int>> deq;
        for(pair<int, int> &p: range) {
            while(!deq.empty() && deq.front().second < p.first) {
                deq.pop_front();
            }

            deq.push_back(p);
            ans = max(ans, (int)deq.size());
        }


        return ans;
    }
};
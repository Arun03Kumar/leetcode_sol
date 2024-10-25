class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Approach 1: sorting
        // sort(begin(nums), end(nums), greater<int>());
        // return nums[k - 1];

        // Approach 2: min-heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int &x: nums) {
            pq.push(x);
            if(pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};
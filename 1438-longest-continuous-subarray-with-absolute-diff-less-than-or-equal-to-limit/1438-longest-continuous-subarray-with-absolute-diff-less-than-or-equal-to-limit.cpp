class Solution {
public:
    typedef pair<int, int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        // use a min heap and max heap to get the max and min element from the subarray between l and r, because if the min and max element will have a difference less than limit then it means every other element will also follows the condition. jump the l pointer to the index of min element when condition doesent satisfied also remove the elements previous to that index from both heaps.
        priority_queue<P > max_pq;
        priority_queue<P, vector<P>, greater<P> > min_pq;

        int l = 0, r = 0, ans = 0;
        while(r < nums.size()) {
            max_pq.push({nums[r], r});
            min_pq.push({nums[r], r});

            while(max_pq.top().first - min_pq.top().first > limit) {
                l = min(max_pq.top().second, min_pq.top().second) + 1;
                while(max_pq.top().second < l) {
                    max_pq.pop();
                }
                while(min_pq.top().second < l) {
                    min_pq.pop();
                }
            }

            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
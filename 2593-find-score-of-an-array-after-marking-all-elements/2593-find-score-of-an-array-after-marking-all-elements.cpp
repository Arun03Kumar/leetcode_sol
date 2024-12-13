class Solution {
public:
    typedef pair<int, int> P;
    long long findScore(vector<int>& nums) {
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = nums.size();
        vector<int> marked(n, 0);
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        int rem_marked = n - 1, ans = 0;
        while(!pq.empty()) {
            int el = pq.top().first;
            int idx = pq.top().second;

            if(marked[idx]) {
                pq.pop();
                continue;
            }

            pq.pop();

            marked[idx] = 1;
            ans += el;
            rem_marked--;

            if(idx == 0) {
                rem_marked--;
                if(n > 1) marked[1] = 1;
            }
            else if(idx == n - 1) {
                rem_marked--;
                marked[n - 1] = 1;
            }
            else {
                rem_marked -= 2;
                marked[idx - 1] = 1;
                marked[idx + 1] = 1;
            }

        }

        return ans;
    }
};
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(begin(gifts), end(gifts));
        long long ans = 0;
        while(k--) {
            int top = pq.top();
            pq.pop();
            pq.push(sqrt(top));
        }

        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};
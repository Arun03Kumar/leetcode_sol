class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq(begin(stones), end(stones));

        while(pq.size() >= 2) {
            int w1 = pq.top();
            pq.pop();

            int w2 = pq.top();
            pq.pop();

            if(w1 != w2) pq.push(abs(w1 - w2));
        }

        return pq.size() == 0 ? 0 : pq.top();
    }
};
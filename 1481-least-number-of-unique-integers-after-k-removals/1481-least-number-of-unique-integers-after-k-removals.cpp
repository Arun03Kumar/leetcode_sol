class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for(int &x: arr) freq[x]++;

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x: freq) pq.push(x.second);

        while(k > 0) {
            if(pq.top() <= k) {
                k -= pq.top();
                pq.pop();
            }
            else break;
        }

        return pq.size();
    }
};
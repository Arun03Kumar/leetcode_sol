class Solution {
public:
    typedef pair<double, vector<int>> P;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P, vector<P>> pq;

        for(vector<int> &v: points) {
            int x = v[0];
            int y = v[1];

            double dist = sqrt(x * x + y * y);
            pq.push({dist, {x, y}});

            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;

        while(!pq.empty()) {
            vector<int> v = pq.top().second;
            pq.pop();

            ans.push_back(v);
        }

        return ans;
    }
};
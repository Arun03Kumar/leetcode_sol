class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int> > projects;
        for(int i = 0; i < profits.size(); i++) {
            projects.push_back({profits[i], capital[i]});
        }

        sort(projects.begin(), projects.end(), [&](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });

        priority_queue<int> pq;
        int i = 0;
        while(k) {
            while(i < profits.size() && projects[i].second <= w) {
                pq.push(projects[i].first);
                i++;
            }
            if(!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
            k--;
        }
        return w;
    }
};
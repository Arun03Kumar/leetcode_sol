class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> actual_index(n);
        for(int i = 0; i < n; i++) {
            actual_index[i] = i;
        }
        // iota(actual_index.begin(), actual_index.end(), 0);

        auto lambda = [&](int &x, int &y) {
            return positions[x] < positions[y];
        };
        sort(actual_index.begin(), actual_index.end(), lambda);

        stack<int> s;

        for(int curr_idx: actual_index) {
            if(directions[curr_idx] == 'R') {
                s.push(curr_idx);
            }
            else {
                while(!s.empty() && healths[curr_idx] > 0) {
                    int top = s.top();
                    s.pop();

                    if(healths[top] > healths[curr_idx]) {
                        healths[curr_idx] = 0;
                        healths[top]--;
                        s.push(top);
                    }
                    else if(healths[curr_idx] > healths[top]) {
                        healths[top] = 0;
                        healths[curr_idx]--;
                    }
                    else {
                        healths[top] = 0;
                        healths[curr_idx] = 0;
                    }
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(healths[i] != 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> time(n);

        for(int i = 0; i < n; i++) {
            int pos = position[i];
            int sp = speed[i];

            time[i] = {pos, sp};
        }

        sort(begin(time), end(time));

        stack<double> st;

        // int temp = (target - time[n - 1].first) / time[n - 1].second;
        // st.push(temp);

        int ans = 0;

        for(int i = n - 1; i >= 0; i--) {
            int rem_dist = target - time[i].first;
            double t = rem_dist / (time[i].second * 1.0);

            if(st.empty()) st.push(t);
            else if(st.top() >= t) st.push(t);
            else {
                while(!st.empty() && st.top() < t) st.pop();
                if(st.empty()) ans++;
                st.push(t);
            }

            // while(!st.empty() && st.top() < t) st.pop();

            // if(st.empty()) ans++;
            // st.push(t);

        }
        cout << st.size();
        return st.empty() ? ans : ans + 1;;
    }
};
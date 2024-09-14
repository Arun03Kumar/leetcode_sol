class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n);
        for(int i = 0; i < n; i++) {
            if(dist[i] < speed[i]) time[i] = 0;
            else {
                time[i] = (dist[i] + speed[i] - 1) / speed[i];
            }
        }

        for(int &x: time) cout << x << " ";

        int counter = 1;
        for(int i = 1; i < n; i++) {
            int rem_time = time[i] - counter;
            if(rem_time <= 0) return i;
            else {
                counter++;
            }
        }
        return n;
    }
};
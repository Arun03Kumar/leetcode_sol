class Solution {
public:
    typedef pair<int, int> P;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // first we have to sort the given array in increasing order of their arrival time, but due to sorting their indexes will be lost, so create additional array with index
        // if we store pair in the pq then it will sort based on first element but if they are equal then it will automatically use another element to sort
        // current time will be used as the parameter to store the tasks which arrival time is less than this, in the pq
        
        int n = tasks.size();
        vector<vector<int>> mod_tasks;
        for(int i = 0; i < n; i++) {
            mod_tasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(begin(tasks), end(tasks));

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> ans;

        int idx = 0;
        int curr_time = mod_tasks[idx][0];

        while(idx < n || !pq.empty()) {

            while(idx < n && mod_tasks[idx][0] <= curr_time) {
                pq.push({mod_tasks[idx][1], mod_tasks[idx][2]});
                idx++;
            }

            int process_time = pq.top().first;
            int index = pq.top().second;
            pq.pop();

            ans.push_back(index);
            curr_time += process_time;
        }

        return ans;
    
    }
};
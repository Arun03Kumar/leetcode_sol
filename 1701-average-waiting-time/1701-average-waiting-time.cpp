class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait_time = 0; 
        int current_time = 0;
        for(auto x: customers) {
            int arrival_time = x[0];
            int cook_time = x[1];

            if(arrival_time > current_time) {
                current_time = arrival_time;
            }

            wait_time += (current_time + cook_time - arrival_time);  
            current_time += cook_time;
        }

        double ans = wait_time / customers.size();
        return ans;
    }
};
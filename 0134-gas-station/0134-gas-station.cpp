class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Brute force
        // int n = gas.size();
        
        // int curr_idx = 0;

        // for(int i = 0; i < n; i++) {
            
        //     int curr_gas = 0;
        //     if(cost[i] <= gas[i]) {
        //         int j = (i + 1) % n;
        //         curr_gas += gas[i] - cost[i];
        //         while(j != i) {
        //             curr_gas += gas[j];
        //             if(curr_gas >= cost[j]) {
        //                 curr_gas -= cost[j];
        //                 j = (j + 1) % n;
        //             }
        //             else {
        //                 break;
        //             }
        //         }

        //         if(i == j) return i;
        //     }

        // }

        // return -1;


        // Approach 2:Optimal Greedy
        // if total cost is greater than all gases then definitely we can't do the task
        // but if total gas >= total cost then it means there will be one index present which will give the answer.
        // so go to each index and check if we can reach to end of the array we do not need to check for a circle

        int n = gas.size();

        int total_gas_sum = accumulate(gas.begin(), gas.end(), 0);
        int total_cost_sum = accumulate(begin(cost), end(cost), 0);

        if(total_gas_sum < total_cost_sum) return -1;

        int total_gas = 0;
        int ans_idx = 0;

        for(int i = 0; i < n; i++) {

            total_gas += gas[i] - cost[i];
            if(total_gas < 0) {
                total_gas = 0;
                ans_idx = i + 1;
            }

        }

        return ans_idx;

    }
};
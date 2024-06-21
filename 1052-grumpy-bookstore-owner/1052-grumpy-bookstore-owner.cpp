class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = 0, r = 0, curr_unsatisfied = 0, max_unsatisfied = -1, satisfied = 0;
        while(r < customers.size()) {
            if(r < minutes && grumpy[r] == 1) {
                curr_unsatisfied += customers[r];
            }
            if(r >= minutes) {
                if(grumpy[r] == 1) {
                    curr_unsatisfied += customers[r];
                }
                if(grumpy[l] == 1) {
                    curr_unsatisfied -= customers[l];
                }
                l++;
            } 
            max_unsatisfied = max(max_unsatisfied, curr_unsatisfied);
            if(grumpy[r] == 0) satisfied += customers[r];
            r++;
        }
        cout << satisfied << " " << max_unsatisfied;
        return max_unsatisfied + satisfied;
    }
};
class Solution {
public:
    vector<int> minOperations(string boxes) {
        // we can find prefix array and postfix array which contains the number of 1's 
        // then we can observe that for an index it is equal to sum of cummulative sum of prefix array and postfix array
        
        int n = boxes.size();
        vector<int> ans(n, 0);

        int curr_sum = 0, cumm_sum = 0;
        for(int i = 0; i < n; i++) {
            ans[i] += cumm_sum;
            curr_sum += boxes[i] - '0';
            cumm_sum += curr_sum;
        }

        curr_sum = 0, cumm_sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] += cumm_sum;
            curr_sum += boxes[i] - '0';
            cumm_sum += curr_sum;
        }

        return ans;
    }
};
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long int sum = 0;
        for(int &x: chalk) sum += x;
        int rem = k % sum;
        for(int i = 0; i < n; i++) {
            if(rem < chalk[i]) return i;
            rem -= chalk[i];
        }

        return -1;
    }
};
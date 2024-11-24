class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        // there are some observations that if there are odd number of negative number then there will be one number which we can't make positive
        // we can easily propagate the negative sign, take an example of grid size 4 and one negative number, we can easily took two adjacent numbers then we can shift the negative sign anywhere in the grid
        // so we just now have to count the number of negative number
        // if it is even then we can make them positve
        // if odd then we can't make one number as positive so why don't we propagatet the sign to the smallest number

        long long sum = 0;
        int min_num = INT_MAX;

        int neg = 0;

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix.size(); j++) {
                sum += abs(matrix[i][j]);
                min_num = min(min_num, abs(matrix[i][j]));

                if(matrix[i][j] < 1) neg++;
            }
        }

        // cout << min_num;

        if(neg & 1) {
            sum -= 2 * abs(min_num);
        }

        return sum;
    }
};
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // Approach 1:
        // int rows = matrix.size();
        // int cols = matrix[0].size();

        // vector<int> min_row, max_cols;

        // for(int row = 0; row < rows; row++) {

        //     int min_in_row = INT_MAX;
        //     for(int col = 0; col < cols; col++) {

        //         min_in_row = min(min_in_row, matrix[row][col]);

        //     }

        //     min_row.push_back(min_in_row);

        // }

        // for(int col = 0; col < cols; col++) {

        //     int max_in_col = INT_MIN;
        //     for(int row = 0; row < rows; row++) {

        //         max_in_col = max(max_in_col, matrix[row][col]);

        //     }

        //     max_cols.push_back(max_in_col);

        // }

        // for(int row = 0; row < rows; row++) {

        //     for(int col = 0; col < cols; col++) {

        //         if(matrix[row][col] == min_row[row] && matrix[row][col] == max_cols[col]) {
        //             return {matrix[row][col]};
        //         }

        //     }

        // }

        // return {};



        // Approach 2:
        // there can be only 1 lucky number in whole matrix, we can prove this by contradiction, take two lucky numbers A & B at different position then we can prove that A > B in one case and in other case B > A. 
        // this can't be possible hence only one lucky number exists.

        // so we can find the element which is maximum in all rows and we can find the element which is minimum in all columns.
        // then compare both if they are same then it means that is lucky number.
        // we are first finding minimum in each rows, but the maximum one will have potential to be the lucky number.

        //similarly, we find max in each row but the minimum would have the potential to be the lucky number.

        int rows = matrix.size();
        int cols = matrix[0].size();

        int max_in_all_rows = INT_MIN;

        for(int r = 0; r < rows; r++) {
            int min_in_curr_row = INT_MAX;
            for(int c = 0; c < cols; c++){
                min_in_curr_row = min(min_in_curr_row, matrix[r][c]);
            }
            max_in_all_rows = max(max_in_all_rows, min_in_curr_row);
        }

        int min_in_all_columns = INT_MAX;

        for(int c = 0; c < cols; c++) {
            int max_in_curr_column = INT_MIN;
            for(int r = 0; r < rows; r++) {
                max_in_curr_column = max(max_in_curr_column, matrix[r][c]);
            }
            min_in_all_columns = min(min_in_all_columns, max_in_curr_column);
        }

        if(max_in_all_rows == min_in_all_columns) {
            return {min_in_all_columns};
        }

        return {};

    }
};
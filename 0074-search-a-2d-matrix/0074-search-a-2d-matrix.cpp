class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low_outer = 0, high_outer = matrix.size() - 1;
        while(low_outer <= high_outer) {
            int mid_outer = low_outer + (high_outer - low_outer) / 2;
            int size = matrix[mid_outer].size();
            if(target > matrix[mid_outer][size - 1]) {
                low_outer = mid_outer + 1;
            }
            else if(target < matrix[mid_outer][0]) {
                high_outer = mid_outer - 1;
            }
            else break;
        }
        if(low_outer > high_outer) return false;
        int mid_outer = low_outer + (high_outer - low_outer) / 2;
        int low_inner = 0, high_inner = matrix[0].size() - 1;
        while(low_inner <= high_inner) {
            int mid_inner = low_inner + (high_inner - low_inner) / 2;
            if(target == matrix[mid_outer][mid_inner])
                return true;
            else if(target > matrix[mid_outer][mid_inner]) {
                low_inner = mid_inner + 1;
            }
            else {
                high_inner = mid_inner - 1;
            }
        }
        return false;
    }
};
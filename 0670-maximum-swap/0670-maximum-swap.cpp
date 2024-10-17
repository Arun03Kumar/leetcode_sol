class Solution {
public:
    int maximumSwap(int num) {
        // Approach 1: for each element we store the index of number which is largest in the right side of that number
        // then we iterate over that suffix array and the first element we get which is smaller than the rigth of it we just swap it
        string temp = to_string(num);
        int n = temp.size();

        vector<int> max_el_pos_in_right(n);
        max_el_pos_in_right[n - 1] = n - 1;

        for(int i = n - 2; i >= 0; i--) {
            int max_in_right = max_el_pos_in_right[i + 1];
            int max_el_in_right = temp[max_in_right];

            if(temp[i] > max_el_in_right) {
                max_el_pos_in_right[i] = i;
            }
            else {
                max_el_pos_in_right[i] = max_in_right;
            }
        }

        for(int i = 0; i < n; i++) {
            int max_right_idx = max_el_pos_in_right[i];
            int max_val = temp[max_right_idx];

            if(temp[i] < max_val) {
                swap(temp[i], temp[max_right_idx]);
                return stoi(temp);
            }    
        }

        return num;
        
    }
};
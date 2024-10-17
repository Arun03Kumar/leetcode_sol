class Solution {
public:
    int maximumSwap(int num) {
        // Approach 1: for each element we store the index of number which is largest in the right side of that number
        // then we iterate over that suffix array and the first element we get which is smaller than the rigth of it we just swap it
        // string temp = to_string(num);
        // int n = temp.size();

        // vector<int> max_el_pos_in_right(n);
        // max_el_pos_in_right[n - 1] = n - 1;

        // for(int i = n - 2; i >= 0; i--) {
        //     int max_in_right = max_el_pos_in_right[i + 1];
        //     int max_el_in_right = temp[max_in_right];

        //     if(temp[i] > max_el_in_right) {
        //         max_el_pos_in_right[i] = i;
        //     }
        //     else {
        //         max_el_pos_in_right[i] = max_in_right;
        //     }
        // }

        // for(int i = 0; i < n; i++) {
        //     int max_right_idx = max_el_pos_in_right[i];
        //     int max_val = temp[max_right_idx];

        //     if(temp[i] < max_val) {
        //         swap(temp[i], temp[max_right_idx]);
        //         return stoi(temp);
        //     }    
        // }

        // return num;


        // Approach 2: constant space
        // we can use 10 sized array which stores the index of that number which is represent by the index of that array
        // means we will store the index of 9 in num at index 9 in the array

        string s = to_string(num);
        int n = s.size();

        vector<int> max_right(10, -1);

        for(int i = 0; i < n; i++) {
            int idx = s[i] - '0';
            max_right[idx] = i;
        }

        for(int i = 0; i < n; i++) {
            char curr = s[i];
            int curr_digit = curr - '0';

            for(int j = 9; j > curr_digit; j--) {
                if(max_right[j] > i) {
                    swap(s[i], s[max_right[j]]);
                    return stoi(s);
                }
            }
        }
        
        return num;
    }
};
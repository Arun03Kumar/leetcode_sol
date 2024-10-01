class Solution {
public:
    int minOperations(string s) {
        // Approach 1:
        // there can be only two possible answer for each string either starts with 0 or starts with 1
        // for length 4 => (0101) or (1010)
        // for length 5 => (01010) or (10101)
        // so either we can create these two strings and compare each element in the given string and which one gives smaller that we can return
        // but we can can observe that there is two possibilty
        // when starts with 0 then on even positions we have 0 and on each odd positions we have 1
        // when starts with 1 then for each even positions we have 1 and for each odd positions we have 0

        int n = s.size();
        int start_with_0 = 0, start_with_1 = 0;

        for(int i = 0; i < n; i++) {

            if(i & 1) {
                if(s[i] == '0') start_with_0++;
                else start_with_1++;
            }
            else {
                if(s[i] == '1') start_with_0++;
                else start_with_1++;
            }

        }

        return min(start_with_0, start_with_1);
    }
};
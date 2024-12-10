class Solution {
public:
    int maximumLength(string s) {
        // Approach 3: Optimal
        // create a datastructure in which row represents the character, since lower case english letters so only 26 rows will be there,
        // max length of any character will be equal to the length of given string
        // so create an array of string length
        // in which each index represents the substring of size (index+1)
        // find substrings and increase the count 
        // start from the end of each array and take cumulative sum that will give the size of that substring
        // eg. "aaaa" since 4a's also contains 3a's, 2a's and 1a's hence we are taking cummulative sum from backwards, so count of 1a's will be 4 and so on
        // for this we store a -> 1, 1, 1, 1
        // when finding substring we store there count and for exact count use cummulative sum

        int n = s.size();
        vector<vector<int>> arr(26, vector<int>(n, 0));

        int i = 0, j = 0;
        char curr_ch = s[0];
        int curr_len = 0;

        while(j < n) {
            if(s[j] == curr_ch) {
                curr_len++;
                arr[curr_ch - 'a'][curr_len - 1]++;
                j++;
            }
            else {
                curr_len = 0;
                curr_ch = s[j];
                i = j;
            }
        }

        int ans = -1;
        for(int i = 0; i < 26; i++) {
            int cumm_sum = 0;
            for(int j = n - 1; j >= 0; j--) {
                cumm_sum += arr[i][j]; 
                if(cumm_sum >= 3) {
                    ans = max(ans, j + 1);
                } 
            }
        }

        return ans;
    }
};
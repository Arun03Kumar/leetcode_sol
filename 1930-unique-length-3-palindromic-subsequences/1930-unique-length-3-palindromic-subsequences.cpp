class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // Approach 1: 
        // since palindrome is of length 3 so first and last character will be same
        // we need to just find the starting and ending indexes for a character then we can find the number of characters between them that will make the palindrome
        // but since we want unique palindromes so it may possible that there are more than one characters present which are same so we need to use set

        // int n = s.size();
        // unordered_set<char> st;

        // for(int i = 0; i < n; i++) {
        //     st.insert(s[i]);
        // }

        // int ans = 0;

        // for(char ch: st) {

        //     int start_idx = -1;
        //     int end_idx = -1;

        //     for(int i = 0; i < n; i++) {
        //         if(ch == s[i]) {
        //             if(start_idx == -1) {
        //                 start_idx = i;
        //             }
        //             else {
        //                 end_idx = i;
        //             }
        //         }
        //     }

        //     unordered_set<char> st2;
        //     for(int j = start_idx + 1; j < end_idx; j++) {
        //         st2.insert(s[j]);
        //     }

        //     ans += st2.size();

        // }

        // return ans;



        // Approach 2: using vector instead of start_idx and end_idx

        int n = s.size();
        vector<pair<int, int>> indexes(26, {-1, -1});

        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';

            if(indexes[idx].first == -1) {
                indexes[idx].first = i;
            }
            else {
                indexes[idx].second = i;
            }
        } 

        int ans = 0;
        for(int i = 0; i < 26; i++) {
            
            if(indexes[i].first != -1) {

                int start = indexes[i].first;
                int end = indexes[i].second;

                unordered_set<char> st;
                for(int j = start + 1; j < end; j++) {
                    st.insert(s[j]);
                }

                ans += st.size();

            }

        }

        return ans;
    }
};
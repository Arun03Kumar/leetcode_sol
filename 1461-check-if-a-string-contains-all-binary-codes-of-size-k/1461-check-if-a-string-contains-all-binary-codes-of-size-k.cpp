class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // instead of creating all substrings and then checking
        // we can find all the unique substring we can form of length k
        // then compare with total number of binary codes we can create 

        unordered_set<string> st;

        if(s.size() < k) return false;

        for(int i = 0; i <= s.size() - k; i++) {
            string substring = s.substr(i, k);
            st.insert({substring});
        }

        int number = pow(2, k);
        return st.size() == number;
    }
};
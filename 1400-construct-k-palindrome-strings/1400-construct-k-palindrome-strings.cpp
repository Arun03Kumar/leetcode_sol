class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();

        // more number of words than all charcters which is not possible
        if(k > n) return false;

        // a single char is also a palindrome
        if(n == k) return true;

        // dry run and check if odd counts are less than k then it is always that palindromes can be made
        vector<int> freq(26, 0);
        for(char ch: s) {
            freq[ch - 'a']++;
        }

        int odd_count = 0;
        for(int &x: freq) {
            if((x & 1)) odd_count++;
        }

        return odd_count <= k;
    }
};
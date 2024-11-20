class Solution {
public:
    int recursion(string &s, int k, int l, int r, int ans, int c_a, int c_b, int c_c) {
        if(c_a >= k && c_b >= k && c_c >= k) return ans;

        if(l > r) return -1;

        int left = INT_MAX, right = INT_MAX;
        if(s[l] == 'a') {
            left = recursion(s, k, l + 1, r, ans + 1, c_a + 1, c_b, c_c);
        }
        else if(s[l] == 'b') {
            left = recursion(s, k, l + 1, r, ans + 1, c_a, c_b + 1, c_c);
        }
        else left = recursion(s, k, l + 1, r, ans + 1, c_a, c_b, c_c + 1);

        if(s[r] == 'a') {
            right = recursion(s, k, l, r - 1, ans + 1, c_a + 1, c_b, c_c);
        }
        else if(s[r] == 'b') {
            right = recursion(s, k, l, r - 1, ans + 1, c_a, c_b + 1, c_c);
        }
        else right = recursion(s, k, l, r - 1, ans + 1, c_a, c_b, c_c + 1);

        return min(left, right);
    }
    int takeCharacters(string s, int k) {
        // return recursion(s, k, 0, s.size() - 1, 0, 0, 0, 0);

        // this is similar to sliding window technique in which we try to increse the window of chars which we can delete from the string
        // so when we reach at any char which can't be deleted we then try to shrink the window
        int n = s.size();
        unordered_map<char, int> mp;

        for(char ch: s) {
            mp[ch]++;
        }

        int i = 0, j = 0;
        int ans = -1;

        if(mp['a'] < k || mp['b'] < k || mp['c'] < k) return ans;

        while(j < n) {
            mp[s[j]]--; // remove the count of char

            // check if any character count is less than k
            // if yes then shrink the window by shifting left pointer
            while(i <= j && (mp['a'] < k || mp['b'] < k || mp['c'] < k)) {
                mp[s[i]]++;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return n - ans;

    }
};
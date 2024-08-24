class Solution {
public:
    bool isAnagram(string s, string t) {
        // Approach 1: sorting
        sort(begin(s), end(s));
        sort(begin(t), end(t));

        return s == t;
    }
};
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;

        int n = s1.size();

        vector<int> diff;

        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }

        if(diff.size() != 2) return false;

        swap(s1[diff[0]], s1[diff[1]]);
        return s1 == s2;
    }
};
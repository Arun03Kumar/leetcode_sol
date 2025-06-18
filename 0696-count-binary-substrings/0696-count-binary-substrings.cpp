class Solution {
public:
    int countBinarySubstrings(string s) {
        // 110001110101
        // [2, 3, 3, 1, 1, 1, 1] // group of consecutive 0's or 1's
        // min(2,3) + min(3, 3) + min(3, 1) + min(1, 1) + min(1, 1) + min(1, 1)
        // 2 + 3 + 1 + 1 + 1 + 1 = 9

        vector<int> groups;
        int count = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                count++;
            }
            else {
                groups.push_back(count);
                count = 1;
            }
        }

        groups.push_back(count); // last group

        int ans = 0;
        for(int i = 1; i < groups.size(); i++) {
            ans += min(groups[i], groups[i - 1]);
        }

        return ans;
    }
};


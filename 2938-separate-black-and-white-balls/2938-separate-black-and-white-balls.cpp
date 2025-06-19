class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0, curr = 0;
        int n = s.size();
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') {
                curr++;
            }
            else ans += curr;
        }

        return ans;
    }
};

// 10001100
// 01001100
// 00101100
// 00011100
// 00011010
// 00011001
// 00010101
// 00010011
// 00001011
// 00000111
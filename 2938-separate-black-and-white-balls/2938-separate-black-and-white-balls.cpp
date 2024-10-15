class Solution {
public:
    long long minimumSteps(string s) {
        int j = s.size() - 1;
        while(j >= 0 && s[j] == '1') j--;
        // j--;
        int i = j - 1;
        long long ans = 0;
        while(i >= 0) {
            if(s[i] == '0') i--;
            else {
                ans += j - i;
                j--;
                i--;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int minFlips(string s) {
        int initial_size = s.size();
        s += s;
        string alternate1 = "", alternate2 = "";
        for(int i = 0; i < s.size(); i++) {
            alternate1 += (i % 2 == 0 ? '1' : '0');
            alternate2 += (i % 2 == 0 ? '0' : '1');
        }
        int l = 0, diff1 = 0, diff2 = 0, res = INT_MAX;
        for(int r = 0; r < s.size(); r++) {
            if(s[r] != alternate1[r])
                diff1++;
            if(s[r] != alternate2[r])
                diff2++;
            
            if(r - l + 1 > initial_size) {
                if(s[l] != alternate1[l])
                    diff1--;
                if(s[l] != alternate2[l])
                    diff2--;
                l++;
            }

            if(r - l + 1 == initial_size)
                res = min(res, min(diff1, diff2));
        }
        return res;

    }
};
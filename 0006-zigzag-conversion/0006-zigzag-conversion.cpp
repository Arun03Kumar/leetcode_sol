class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string> ans(numRows);
        int n = s.size();
        int i = 0;

        int idx = 0, dir = 1;
        while(i < n) {
            char curr = s[i];
            ans[idx].push_back(curr);

            idx += dir;
    
            if(idx == numRows - 1) dir = -1;
            else if(idx == 0) dir = 1;
            i++;
        }

        string res = "";
        for(string &x: ans) res.append(x);

        return res;
    }
};
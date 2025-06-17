class Solution {
public:
    vector<int> diStringMatch(string s) {
        int k = 0, j = s.size();
        vector<int> ans(j + 1);

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'I') ans[i] = k++;
            else ans[i] = j--;
        }

        ans[s.size()] = j;

        return ans;
    }
};
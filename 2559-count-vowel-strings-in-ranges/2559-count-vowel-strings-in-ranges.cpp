class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n, 0), ans;

        string vow = "aeiou";
        if(vow.find(words[0][0]) != string::npos && vow.find(words[0].back()) != string::npos) {
            prefix[0] = 1;
        }

        for(int i = 1; i < n; i++) {
            if(vow.find(words[i][0]) != string::npos && vow.find(words[0].back()) != string::npos) {
                prefix[i] = prefix[i - 1] + 1;
            }
            else {
                prefix[i] = prefix[i - 1];
            }
        }

        for(vector<int> &q: queries) {
            int l = q[0];
            int r = q[1];

            int temp = (l != 0) ? prefix[r] - prefix[l - 1] : prefix[r];
            ans.push_back(temp);
        }

        return ans;
    }
};
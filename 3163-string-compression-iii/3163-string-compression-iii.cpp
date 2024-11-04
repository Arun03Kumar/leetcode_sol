class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        int cnt = 1;
        char prev = word[0];
        string ans = "";
        for(int i = 1; i < n; i++) {
            if(word[i] == prev && cnt < 9) {
                cnt++;
            }
            else if(cnt >= 9) {
                ans += to_string(cnt);
                ans.push_back(prev);
                cnt = 1;
            }
            else {
                ans += to_string(cnt);
                ans.push_back(prev);
                cnt = 1;
                prev = word[i];
            }

        }
        ans += to_string(cnt);
        ans.push_back(prev);

        return ans;
    }
};
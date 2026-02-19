class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        char ch = 'a';
        vector<string> ans;
        while(ch <= 'z') {
            int cnt = INT_MAX;
            for(string x: words) {
                int c = count(begin(x), end(x), ch);
                cnt = min(cnt, c);
            }

            if(cnt != INT_MAX) {
                for(int i = 0; i < cnt; i++) {
                    ans.push_back(string(1, ch));
                }
            }
            ch++;
        }
        return ans;
    }
};
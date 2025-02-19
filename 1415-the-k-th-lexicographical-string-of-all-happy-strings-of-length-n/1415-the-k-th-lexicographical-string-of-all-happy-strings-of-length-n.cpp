class Solution {
public:
    void backtracking(vector<string> &ans, string curr, int &n) {
        if(curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++) {
            if(!curr.empty() && curr.back() == ch) continue;
            curr.push_back(ch);
            backtracking(ans, curr, n);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        string curr = "";
        backtracking(ans, curr, n);

        if(ans.size() < k) return "";

        return ans[k - 1];
    }
};
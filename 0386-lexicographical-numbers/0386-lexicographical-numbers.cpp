class Solution {
public:
    void recursion(int curr, int n, vector<int> &ans) {
        if(curr > n) return;

        ans.push_back(curr);

        for(int i = 0; i <= 9; i++) {
            int new_num = curr * 10 + i;
            
            if(new_num > n) return;
            recursion(new_num, n, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for(int i = 1; i <= 9; i++) {
            recursion(i, n, ans);
        }

        return ans;
    }
};
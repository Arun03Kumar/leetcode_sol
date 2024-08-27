class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1, 1}};

        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1, 1});

        for(int i = 2; i < numRows; i++) {
            vector<int> temp;
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    temp.push_back(1);
                    continue;
                }
                
                int a = ans[i - 1][j - 1];
                int b = ans[i - 1][j];
                temp.push_back(a + b);
            }

            ans.push_back(temp);
        }

        return ans;

    }
};
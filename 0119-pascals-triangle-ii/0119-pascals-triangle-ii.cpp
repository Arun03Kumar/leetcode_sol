class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1, 1};
        
        vector<int> ans(rowIndex + 1);
        ans[0] = ans[1] = 1;

        for(int i = 2; i <= rowIndex; i++) {
            ans[i] = 1;
            for(int j = i - 1; j > 0; j--) {
                ans[j] = ans[j] + ans[j - 1];
            }
        }

        return ans;
        
    }
};
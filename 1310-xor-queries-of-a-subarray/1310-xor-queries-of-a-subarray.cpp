class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix_xor(n, 0);
        prefix_xor[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefix_xor[i] = prefix_xor[i - 1] ^ arr[i];
        }

        vector<int> ans;

        for(auto &x: queries) {
            int l = x[0];
            int r = x[1];

            int temp = prefix_xor[r] ^ (l - 1 >= 0 ? prefix_xor[l - 1] : 0);
            ans.push_back(temp);
        }
        
        return ans;
    }
};
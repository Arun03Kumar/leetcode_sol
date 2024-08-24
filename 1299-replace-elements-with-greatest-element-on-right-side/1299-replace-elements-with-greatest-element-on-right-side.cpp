class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans = arr;

        for(int i = 0; i < arr.size() - 1; i++) {
            int mx_el = *max_element(begin(arr) + i + 1, end(arr));
            ans[i] = mx_el;
        }

        int n = arr.size();
        ans[n - 1] = -1;
        return ans;
    }
};
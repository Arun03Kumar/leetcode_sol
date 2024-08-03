class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(begin(target), end(target));
        sort(arr.begin(), arr.end());

        return target == arr;
    }
};
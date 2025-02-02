class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(begin(sorted), end(sorted));

        for(int i = 0; i < n; i++) {
            int flag = 1;
            for(int j = 0; j < n; j++) {
                if(nums[(j + i) % n] != sorted[j]) {
                    flag = 0;
                    break;
                }
            }

            if(flag) return true;
        }

        return false;
    }
};
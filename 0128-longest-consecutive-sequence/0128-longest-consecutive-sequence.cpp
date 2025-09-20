class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> st(begin(nums), end(nums));
        int ans = 1;

        for(int num: st) {
            if(st.find(num - 1) == st.end()) {
                int curr = num;
                int count = 1;
                while(st.find(curr + 1) != st.end()) {
                    curr += 1;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
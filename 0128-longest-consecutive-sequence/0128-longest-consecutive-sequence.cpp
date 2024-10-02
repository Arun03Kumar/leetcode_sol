class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // so we store array elements in unordered_Set to search them in O(1)
        // so for getting a sequqnec we just need to check if array contains one previous element and one next element in the array
        // so we keep on checking this for left and right

        if(nums.size() == 0) return 0;
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 1;
        for(int i = 0; i < nums.size(); i++) {
            int prev = nums[i] - 1, next = nums[i] + 1;

            while(st.find(prev) != st.end()) prev -= 1;
            while(st.find(next) != st.end()) next += 1;

            ans = max(ans, next - prev - 1);
        }

        return ans;
    }
};
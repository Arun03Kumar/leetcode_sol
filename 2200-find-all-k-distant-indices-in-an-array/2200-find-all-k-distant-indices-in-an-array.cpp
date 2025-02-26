class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();

        set<int> st;
        for(int i = 0; i < n; i++) {
            if(nums[i] == key) st.insert(i);
        }

        for(int i = 0; i < n; i++) {
            for(int x: st) {
                if(abs(i - x) <= k) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        sort(begin(ans), end(ans));
        return ans;
    }
};
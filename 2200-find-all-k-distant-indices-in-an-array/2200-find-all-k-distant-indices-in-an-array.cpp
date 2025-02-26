class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        // vector<int> ans;
        // int n = nums.size();

        // set<int> st;
        // for(int i = 0; i < n; i++) {
        //     if(nums[i] == key) st.insert(i);
        // }

        // for(int i = 0; i < n; i++) {
        //     for(int x: st) {
        //         if(abs(i - x) <= k) {
        //             ans.push_back(i);
        //             break;
        //         }
        //     }
        // }

        // sort(begin(ans), end(ans));
        // return ans;


        // Approach 2:
        // search for key, then go to k elements left and right of it and store the index in the array
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(nums[i] == key) {
                int left = max(0, i - k);
                int right = min(i + k, n - 1);

                if(ans.size() != 0) {
                    left = max(left, ans.back() + 1); // this is the case for overlapping 
                }

                for(int j = left; j <= right; j++) {
                    ans.push_back(j);
                }
            }
        }

        return ans;
    }
};
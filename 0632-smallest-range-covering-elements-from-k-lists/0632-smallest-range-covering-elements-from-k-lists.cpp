class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // so we created a pointer for each of the list starting from index 0;
        // then we search the minimum and maximum elements whcih are pointed by those pointers
        // we also store the index of smallest number
        int k = nums.size();
        vector<int> pointers(k, 0);

        vector<int> ans = {-1000000, 1000000};

        while(true) {
            int min_el = INT_MAX;
            int max_el = INT_MIN;
            int min_el_idx = 0;

            for(int i = 0; i < k; i++) {
                int ith_list = i;
                int el_in_ith_list = pointers[i];

                int el = nums[ith_list][el_in_ith_list];

                if(el < min_el) {
                    min_el = el;
                    min_el_idx = ith_list;
                }

                max_el = max(max_el, el);
            }

            if(max_el - min_el < ans[1] - ans[0]) {
                ans[0] = min_el;
                ans[1] = max_el;
            }

            int next_idx = pointers[min_el_idx] + 1;

            if(next_idx >= nums[min_el_idx].size()) break;

            pointers[min_el_idx] = next_idx;
        }

        return ans;
    }
};
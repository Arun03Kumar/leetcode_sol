class Solution {
public:
    #define MOD 1000000007
    vector<int> smaller_on_left(vector<int> &nums) {
        stack<int> st;
        vector<int> res(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if(st.empty()) {
                res[i] = -1;
            }
            else {
                res[i] = st.top();
            }

            st.push(i);

        }

        return res;
    }

    vector<int> smaller_on_right(vector<int> &nums) {
        stack<int> st;
        vector<int> res(nums.size());

        for(int i = nums.size() - 1; i >= 0; i--) {
            
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if(st.empty()) {
                res[i] = nums.size();
            }
            else {
                res[i] = st.top();
            }

            st.push(i);

        }

        return res;
    }

    int maxSumMinProduct(vector<int>& nums) {

        // so basically we create subarrays by considering each element as smallest in the subarray which contains maximum elements. so this way there will be only one possibility to create that subarray.

        // we create prefix sum to calculate sum of subarrays in O(1)

        //for each element we find the index of just smaller element than current element, simillarly we find the just smaller element in the right side.

        // from these indexes we can find the sum of the subarray which contains the maximum sum by considering the current element as minimum.

        // we are using monotonic stack to get the indexes, we pop till the top of stack contains larger elements than current element.
        // if stack is empty it means it didn't found any smaller element on the left or right hence we store the -1 or size of array.



        int n = nums.size();

        vector<long long> prefix_sum(n + 1,  0);

        for(int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }

        // this array gives the index of each element which is just smaller than current element in the left of array
        vector<int> smaller_idx_on_left = smaller_on_left(nums);
        // this array gives the index of each element which is just smaller than current element in the right of array
        vector<int> smaller_idx_on_right = smaller_on_right(nums);

        long long ans = LONG_MIN;
        for(int i = 0; i < n; i++) {

            int consider_min = nums[i];

            int left_smaller = smaller_idx_on_left[i];
            int right_smaller = smaller_idx_on_right[i];

            long long subarray_sum = prefix_sum[right_smaller] - prefix_sum[left_smaller + 1];
            long long min_product = consider_min * subarray_sum;

            ans = max(ans, min_product);

        }

        return (int)(ans % MOD);
    }
};
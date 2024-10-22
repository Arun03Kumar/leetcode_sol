class Solution {
public:
    vector<int> get_NSL(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(st.empty()) ans[i] = -1;
            else {
                while(!st.empty() && arr[st.top()] > arr[i]) {
                    st.pop();
                }

                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

     vector<int> get_NSR(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            if(st.empty()) ans[i] = n;
            else {
                // here there is small change because if multiple same numbers are present then if we create subarray for each of them then there will be some subarrays which are created multiple times so they will contribute more sum in the array, hence we avoided here
                while(!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }

                if(st.empty()) ans[i] = n;
                else ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        // for each element we need to find number of arrays in which that element is smallest
        // with this we can find the sum easily we just multiply the number with number of subarrays in which that element is smallest
        // ex. [1, 2, 3], for 3 there is only one subarray in which 3 is smallest so it will contribute to the total sum as 3*1
        // for 1 -> (1), (1, 2), (1,2,3) in these 3 subarrays it will be smallest so the contribution will be 1*3

        // but how do we find that how many subarrays are there for each element in which that element is smallest
        // so for that we need to find number of elements which are greater than the current element, in both left and right side
        // ex for 2 there are 0 elements which are greater than 0 in left array and 1 element is greater in the right array
        // so there will be (0 + 1) * (1 + 1) => 2 subarrays in which 2 will be smallest
        // so with this we can find this for each element

        // and this is simillar to finding next smaller in the left and next smaller in the right array
        // this is done by stack
        // so we store the index of elements in the stack

        int n = arr.size();

        vector<int> next_smaller_in_left = get_NSL(arr);
        vector<int> next_smaller_in_right = get_NSR(arr);

        long long sum = 0;
        int M = 1e9 + 7;

        for(int i = 0; i < n; i++) {
            long long num_smaller_left = i - next_smaller_in_left[i];

            long long num_smaller_right = next_smaller_in_right[i] - i;

            long long total_ways_i_min = num_smaller_left * num_smaller_right;

            long long sum_i_min = arr[i] * total_ways_i_min;

            sum = (sum + sum_i_min) % M;
        }

        return sum;
    }
};
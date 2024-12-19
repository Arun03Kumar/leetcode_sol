class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // Approach 1: prefix/suffix arrays
        // for each element if max element before i is smaller than the min element after/at i then it means we can break them into a chunk
        // so just create max and min prefix and suffix arrays

        // int n = arr.size();
        // vector<int> prefix_i(n), suffix_after_i(n);
        // prefix_i[0] = arr[0];
        // suffix_after_i[n - 1] = arr[n - 1];

        // for(int i = 1; i < n; i++) {
        //     prefix_i[i] = max(prefix_i[i - 1], arr[i]);
        // }

        // for(int i = n - 2; i >= 0; i--) {
        //     suffix_after_i[i] = min(arr[i], suffix_after_i[i + 1]);
        // }

        // int ans = 0;
        // for(int i = 0; i < n; i++) {
        //     int max_before_i = i > 0 ? prefix_i[i - 1] : -1;
        //     int min_after_i = suffix_after_i[i];
        //     if(max_before_i < min_after_i) {
        //         ans++;
        //     }
        // }

        // return ans;


        // Approach 2: cummulative sum
        // we know the array after sorting so we know the cummulative sum
        // if cummulative sum of sorted array is same as the cummulative sum of given array at any index then we can break into chunks

        int n = arr.size();

        // we don't need this cumm array since number are from 0 to n-1 so we can have a cumm variable and just add the index
        // vector<int> cumm_sum(n);
        // cumm_sum[0] = 0;
        // for(int i = 1; i < n; i++) {
        //     cumm_sum[i] = i + cumm_sum[i - 1];
        // }

        int ans = 0, temp = 0, cumm = 0;
        for(int i = 0; i < n; i++) {
            cumm += i;
            temp += arr[i];

            if(temp == cumm) ans++;
        }

        return ans;
    }
};
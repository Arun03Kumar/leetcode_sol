class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // we need to handle two cases
        // one normal kadane's algorith in which max subarray sum is present in the normal array
        // but if subarray sum is present in the circular part then we have to use a trick
        // we know that circular sum + non curcular sum will be equal to total_sum
        // so we can argue that if circular sum is max subarray sum then non circular sum would definitly be min subarray sum
        // so we can find max subarray sum and min subarray sum then we can subtraact min_subarray sum from total_sum
        // and return which is maximum in both
        

        int total_sum = 0;

        int max_sum = INT_MIN;
        int curr_max = 0;

        int min_sum = INT_MAX;
        int curr_min = 0;

        for(int &x: nums) {
            total_sum += x;

            curr_max += x;
            max_sum = max(max_sum, curr_max);
            if(curr_max < 0) curr_max = 0;

            curr_min += x;
            min_sum = min(min_sum, curr_min);
            if(curr_min > 0) curr_min = 0;
        }

        if(total_sum == min_sum) return max_sum;

        return max(max_sum, total_sum - min_sum);
    }
};
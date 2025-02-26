class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // int n = nums.size();
        // int curr = INT_MAX, ans;
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         for(int k = j + 1; k < n; k++) {
        //             int sum = nums[i] + nums[j] + nums[k];
        //             cout << sum << " ";
        //             if(abs(target - sum) < curr) {
        //                 ans = sum;
        //                 curr = abs(target - sum);
        //             }
        //         }
        //     }
        // }
        // return ans;

        sort(begin(nums), end(nums));
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                }

                if(sum < target) left++;
                else if(sum > target) right--;
                else return target;
            }
        }

        return ans;
    }
};
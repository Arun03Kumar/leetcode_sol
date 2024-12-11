class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // Approach 1:
        // for(int i = 0; i < nums.size(); i++) {
        //     if((nums[i] & 1) == 0 && (i & 1) != 0) {
        //         int j = i + 1;
        //         while(j < nums.size() && nums[j] % 2 == 0) {
        //             j += 2;
        //         }
        //         swap(nums[i], nums[j]);
        //     }

        //     if((nums[i] & 1) == 1 && (i & 1) != 1) {
        //         int j = i + 1;
        //         while(j < nums.size() && nums[j] % 2 == 1) {
        //             j += 2;
        //         }
        //         swap(nums[i], nums[j]);
        //     }
        // }

        // return nums;

        // Approach 2: Two pointers
        int even = 0, odd = 1, n = nums.size();

        while(even < n && odd < n) {
            while(even < n && nums[even] % 2 == 0) even += 2;
            while(odd < n && nums[odd] % 2 == 1) odd += 2;

            if(even < n && odd < n)
                swap(nums[even], nums[odd]);
        }

        return nums;
    }
};
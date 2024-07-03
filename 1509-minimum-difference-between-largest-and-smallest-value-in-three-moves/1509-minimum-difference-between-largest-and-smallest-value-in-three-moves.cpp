class Solution {
public:
    int minDifference(vector<int>& nums) {
        // there will be only four cases:
        //1. change the last 3 values to the minimum value in this case (n-4)th will be max and 0th will be minimum.
        //2. either change the last two values equal to the (n-3)rd value and minimum value to the first value so this way minimum will be 1st value and maximum will be n-3rd value.
        // 3. change last element to the second last and first two element to the third element.
        //4. change the starting 3 elements to the 4th element.
        // then find the minimum of all.
        int n = nums.size();
        if(n <= 4) return 0;
        sort(nums.begin(), nums.end());
        
        int first_case = nums[n - 4] - nums[0];
        int second_case = nums[n - 3] - nums[1];
        int third_case = nums[n - 2] - nums[2];
        int fourth_case = nums[n - 1] - nums[3];
        return min(first_case, min(second_case, min(third_case, fourth_case)));  
    }
};
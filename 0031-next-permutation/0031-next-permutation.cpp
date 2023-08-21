class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       for(int i = nums.size() - 1; i > 0; i--) {
           if(nums[i] > nums[i-1]) {
               int x = nums[i-1], first = nums[i], idx = i;
               for(int j = i-1; j <= nums.size() - 1; j++) {
                   if(nums[j] > x && nums[j] < first) {
                      first = nums[j];
                      idx = j;
                   }
               }
               swap(nums[i-1], nums[idx]);
               sort(nums.begin() + i, nums.end());
               return;
           }
       }
       sort(nums.begin(), nums.end());
    }
};
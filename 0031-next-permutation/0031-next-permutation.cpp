class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int  i = n - 1;
        while(i--) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] >= nums[j]) continue;
            while(i >= 0 && j < n && nums[i] < nums[j]) {
                j++;
            }
            swap(nums[i], nums[j - 1]);
            reverse(begin(nums) + i + 1 , end(nums));
            return;
        }
        }
        reverse(begin(nums), end(nums));
    }
};
// 1 2 25 47 48
// 1 2 25 48 47
// 1 2 47 25 48
// 1 2 47 48 25
// 1 2 48 25 47
// 1 2 48 47 25 
// 1 25 2 47 48
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = nums.size() - 1, count  = 0, i = 0;
       while (i <= right) {
           if(nums[i] != val) {
               count++;
           }
           else {
               if(nums[right] == val) {
                   right--;
                   continue;
               }else {
                   swap(nums[i], nums[right]);
                   count++;
               }
           }
           i++;
       }
       return count;
    }
};
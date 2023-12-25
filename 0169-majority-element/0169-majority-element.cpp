class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element, count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                element = nums[i];
                count = 1;
            }
            else if(nums[i] == element) {
                count++;
            }
            else {
                count--;
            }
        }
        int cnt = 0;
        for(auto x: nums) {
            if(x == element) cnt++;
        }
        if(cnt > (nums.size() / 2)) return element;
        return -1;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], counter = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(counter == 0) {
                candidate = nums[i];
                counter = 1;
            }
            else if(nums[i] == candidate) {
                counter++;
            }
            else {
                counter--;
            }
        }
        return candidate;
    }
};
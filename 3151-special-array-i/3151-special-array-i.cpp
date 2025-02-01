class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            int x = (nums[i - 1] & 1);
            int y = (nums[i] & 1);
            if(x == y) return false;
        }

        return true;
    }
};
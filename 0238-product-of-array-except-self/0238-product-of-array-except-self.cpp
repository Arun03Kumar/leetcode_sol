class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // for division approach we need to take care about the 0 values present in the array
        // so for that we maintain a variable which stores the count of 0s

        vector<int> ans;
        int mult = 1, without_0 = 1;
        int count = 0;
        for(int &x: nums) {
            mult *= x;
            if(x == 0) count++;
            else without_0 *= x;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                ans.push_back(mult / nums[i]);
            }
            else {
                if(count - 1 > 0) ans.push_back(0);
                else ans.push_back(without_0);
            }
        }

        return ans;
    }
};
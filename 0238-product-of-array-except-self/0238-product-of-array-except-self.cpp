class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // for division approach we need to take care about the 0 values present in the array
        // so for that we maintain a variable which stores the count of 0s
        // so if number of 0s is greater than 1 then if we are at 0 then we simply check the count value if it is greater than 0
        // else we compute the multiplication with out including 0 in it 

        // vector<int> ans;
        // int mult = 1, without_0 = 1;
        // int count = 0;
        // for(int &x: nums) {
        //     mult *= x;
        //     if(x == 0) count++;
        //     else without_0 *= x;
        // }

        // for(int i = 0; i < nums.size(); i++) {
        //     if(nums[i] != 0) {
        //         ans.push_back(mult / nums[i]);
        //     }
        //     else {
        //         if(count - 1 > 0) ans.push_back(0);
        //         else ans.push_back(without_0);
        //     }
        // }

        // return ans;

        // Approach 2: maintian two arrays left prefix mult and right prefix mult
        // these arrays stores the multiplication of elemets in left side and in right side, so we just have to multiply the left ans right side for any index.

        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        for(int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
            right[n - i - 1] = right[n - i] * nums[n - i];
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(left[i] * right[i]);
        }

        return ans;


    }
};
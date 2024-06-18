class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // reverse whole array
        //reverse starting k elements
        //reverse last n-k elements.
       int n = nums.size();
        if(k == 0) return;
        k = k % n; // we do this because k may be greater than n so if length of array is 4 and k is also 4 then it means we are moving the array 0 times.
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end()); 
    }
};
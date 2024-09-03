class NumArray {
public:
    vector<int> prefix_sum;
public:
    NumArray(vector<int>& nums) {
        prefix_sum.resize(nums.size());
        prefix_sum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            prefix_sum[i] = nums[i] + prefix_sum[i - 1];
        }

        // for(int x: arr) {
        //     cout << x << " ";
        // }
    }
    
    int sumRange(int left, int right) {
        int l = left > 0 ? prefix_sum[left - 1] : 0;
        return prefix_sum[right] - l;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
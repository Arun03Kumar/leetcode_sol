class NumArray {
public:
    vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        arr.resize(nums.size());
        arr[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            arr[i] = nums[i] + arr[i - 1];
        }

        for(int x: arr) {
            cout << x << " ";
        }
    }
    
    int sumRange(int left, int right) {
        int l = left > 0 ? arr[left - 1] : 0;
        return arr[right] - l;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
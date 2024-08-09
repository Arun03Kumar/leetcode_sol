class NumArray {
public:
    int n;
    vector<int> segment_tree;

    NumArray(vector<int>& nums) {
        n = nums.size();
        segment_tree.resize(n * 4);
        build(nums, 0, 0, n - 1);
    }

    void build(vector<int> &nums, int node, int left, int right) {

        if(left == right) {
            segment_tree[node] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;

        build(nums, node * 2 + 1, left, mid);
        build(nums, node * 2 + 2, mid + 1, right);

        segment_tree[node] = segment_tree[node * 2 + 1] + segment_tree[node * 2 + 2];

    }

    void update_helper(int node, int left, int right, int index, int val) {

        if(left == right) {
            segment_tree[node] = val;
            return;
        }

        int mid = left + (right - left) / 2;

        if(index <= mid) {
            update_helper(node * 2 + 1, left, mid, index, val);
        }
        else {
            update_helper(node * 2 + 2, mid + 1, right, index, val);
        }

        segment_tree[node] = segment_tree[node * 2 + 1] + segment_tree[node * 2 + 2];

    }
    
    void update(int index, int val) {
        update_helper(0, 0, n - 1, index, val);
    }

    int range_helper(int node, int l, int r, int left, int right) {

        if(right < l || r < left) return 0;

        if(l >= left && r <= right) {
            return segment_tree[node];
        }

        int mid = l + (r - l) / 2;

        int q_l = range_helper(node * 2 + 1, l, mid, left, right);
        int q_r = range_helper(node * 2 + 2, mid + 1, r, left, right);

        return q_l + q_r;

    }
    
    int sumRange(int left, int right) {
        return range_helper(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
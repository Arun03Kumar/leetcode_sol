class Solution {
public:
    int merge(vector<int> &nums, int l, int mid, int r) {
        vector<int> temp;
        int ans = 0, j = mid + 1;

        for(int i = l; i <= mid; i++) {
            while(j <= r && nums[i] > 2LL * nums[j]) j++;

            ans += j - mid - 1;
        }

        int i = l;
        j = mid + 1;
        while(i <= mid && j <= r) {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            }
            else {
                temp.push_back(nums[j++]);
            }
        }

        while(i <= mid) {
            temp.push_back(nums[i++]);
        }

        while(j <= r) temp.push_back(nums[j++]);

        for(int k = l; k <= r; k++) nums[k] = temp[k - l];

        return ans;
    }
    
    int merge_sort(vector<int> &nums, int l, int r) {
        int ans = 0;
        if(l < r) {
            int mid = l + (r - l) / 2;

            ans += merge_sort(nums, l, mid);
            ans += merge_sort(nums, mid + 1, r);
            ans += merge(nums, l, mid, r);
        }

        return ans;
    }

    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size() - 1);
    }
};
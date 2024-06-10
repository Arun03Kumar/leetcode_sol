class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ansPtr = m + n - 1, first = m - 1, second = n - 1;
        while(first >= 0 && second >= 0) {
            if(nums1[first] >= nums2[second]) {
                nums1[ansPtr--] = nums1[first--];
            }
            else {
                nums1[ansPtr--] = nums2[second--];
            }
        } 
        while(first >= 0) {
            nums1[ansPtr--] = nums1[first--];
        }
        while(second >= 0) {
            nums1[ansPtr--] = nums2[second--];
        }
        if(m == 0) nums1 = nums2;
    }
};
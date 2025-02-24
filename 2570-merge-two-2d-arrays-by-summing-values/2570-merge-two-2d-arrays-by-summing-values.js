/**
 * @param {number[][]} nums1
 * @param {number[][]} nums2
 * @return {number[][]}
 */
var mergeArrays = function(nums1, nums2) {
    let m = nums1.length, n = nums2.length;
    let i = 0, j = 0;

    let ans = [];

    while(i < m && j < n) {
        if(nums1[i][0] === nums2[j][0]) {
            let id = nums1[i][0], sum = nums1[i][1] + nums2[j][1];
            ans.push([id, sum]);
            i++;
            j++;
        }
        else if(nums1[i][0] < nums2[j][0]) {
            ans.push(nums1[i]);
            i++;
        }
        else {
            ans.push(nums2[j]);
            j++;
        }
    }

    while(i < m) {
        ans.push(nums1[i]);
        i++;
    }

    while(j < n) {
        ans.push(nums2[j]);
        j++;
    }

    return ans;
};
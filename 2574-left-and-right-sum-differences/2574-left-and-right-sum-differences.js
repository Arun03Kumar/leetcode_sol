/**
 * @param {number[]} nums
 * @return {number[]}
 */
var leftRightDifference = function(nums) {
    let leftSum = 0, rightSum = 0;
    nums.forEach(x => rightSum += x);

    let ans = []
    for(let i = 0; i < nums.length; i++) {
        leftSum += nums[i];
        ans.push(Math.abs(rightSum - leftSum));
        rightSum -= nums[i];
    }

    return ans;
};
/**
 * @param {number[]} arr
 * @return {number}
 */
var numOfSubarrays = function(arr) {
    // basically when we create prefix array we get the sum if sum is odd then we get an integer which sums with previous even numbers to get odd number
    // vice versa is also true

    // let mod = 1e9 + 7;

    // let n = arr.length;
    // let prefix = []
    // prefix.push(arr[0]);

    // for(let i = 1; i < n; i++) {
    //     prefix.push(prefix[i - 1] + arr[i]);
    // }

    // let oddCount = 0, evenCount = 1;
    // let ans = 0;

    // for(let x of prefix) {
    //     if(x % 2 == 0) {
    //         ans += oddCount;
    //         evenCount++;
    //     }
    //     else {
    //         ans += evenCount;
    //         oddCount++;
    //     }
    // }

    // return ans % mod;


    // we can also use prefix in the same loop
    let mod = 1e9 + 7;
    let prefix = 0, evenCount = 1, oddCount = 0, ans = 0;

    for(let num of arr) {
        prefix += num;
        if(prefix % 2 == 0) {
            ans += oddCount;
            evenCount++;
        }
        else {
            ans += evenCount;
            oddCount++;
        }
    }

    return ans % mod;
};
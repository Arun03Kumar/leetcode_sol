/**
 * @param {string} customers
 * @return {number}
 */
var bestClosingTime = function(customers) {
    let ncount = 0, ycount = 0;
    for(let x of customers) {
        if(x === 'Y') ycount++;
    }

    let count = Infinity, ans;
    for(let i = 0; i <= customers.length; i++) {
        if(ycount + ncount < count) {
            ans = i;
            count = ycount + ncount;
        }
        if(customers[i] === 'Y') {
            ycount--;
        }
        else ncount++;
    }

    return ans;
};

// yyny
// 0 -> 3 + 0 -> 3
// 1 -> 2 + 0 -> 2
// 2 -> 1 + 0 -> 1
// 3 -> 1 + 1 -> 2
// 4 -> 0 + 1 -> 1
// ycount -> 3
// ncount -> 0
// i -> 0 -> 3 + 0 -> 3, ycount--
// i -> 1 -> 2 + 0 -> 2, ycount--
// i -> 2 -> 1 + 0 -> 1, ncpint++
// i -> 3 -> 1 + 1 -> 2, ycount--
// i -> 4 -> 

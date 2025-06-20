/**
 * @param {number[]} security
 * @param {number} time
 * @return {number[]}
 */
var goodDaysToRobBank = function(security, time) {
    let left = new Array(security.length).fill(0)
    let right = new Array(security.length).fill(0)
    
    for(let i = 1; i < security.length; i++) {
        if(security[i] <= security[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
        else {
            left[i] = 0;
        }
    }

    for(let i = security.length - 2; i >= 0; i--) {
        if(security[i] <= security[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
        else {
            right[i] = 0;
        }
    }

    for(const x of left) process.stdout.write(x + " ");

    let ans = [];
    for(let i = time; i < security.length - time; i++) {
        if(left[i] >= time && right[i] >= time) ans.push(i);
    }

    return ans;
};


// 5 3 3 3 5 6 2

// 0 1 2 3 0 0 1
// 0 4 3 2 1 0 0
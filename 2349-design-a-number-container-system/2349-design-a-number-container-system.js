/**
 * @param {number} index
 * @param {number} number
 * @return {void}
 */
var NumberContainers = function() {
    this.idxToNum = new Map();   // Map: index -> number
    this.numToIdx = new Map();   // Map: number -> sorted array of indices
};

/** 
 * @param {number} index 
 * @param {number} number
 * @return {void}
 */
NumberContainers.prototype.change = function(index, number) {
    // If index already holds a number, remove it from its sorted array.
    if (this.idxToNum.has(index)) {
        let prev = this.idxToNum.get(index);
        if (this.numToIdx.has(prev)) {
            let arr = this.numToIdx.get(prev);
            let pos = binarySearch(arr, index);
            if (pos < arr.length && arr[pos] === index) {
                arr.splice(pos, 1);  // Remove the old index.
            }
            if (arr.length === 0) {
                this.numToIdx.delete(prev);
            }
        }
    }
    
    // Update the mapping.
    this.idxToNum.set(index, number);
    
    // Insert the index into the sorted array for the new number.
    if (!this.numToIdx.has(number)) {
        this.numToIdx.set(number, []);
    }
    let arr2 = this.numToIdx.get(number);
    let pos2 = binarySearch(arr2, index);
    arr2.splice(pos2, 0, index);
};

/** 
 * @param {number} number
 * @return {number}
 */
NumberContainers.prototype.find = function(number) {
    if (!this.numToIdx.has(number) || this.numToIdx.get(number).length === 0) {
        return -1;
    }
    return this.numToIdx.get(number)[0];  // The sorted array's first element is the smallest index.
};

/** 
 * Helper: binarySearch returns the index at which `target` should be inserted in `arr`
 * to maintain sorted order.
 */
function binarySearch(arr, target) {
    let left = 0, right = arr.length;
    while (left < right) {
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

/** 
 * Your NumberContainers object will be instantiated and called as such:
 * var obj = new NumberContainers()
 * obj.change(index, number)
 * var param_2 = obj.find(number)
 */

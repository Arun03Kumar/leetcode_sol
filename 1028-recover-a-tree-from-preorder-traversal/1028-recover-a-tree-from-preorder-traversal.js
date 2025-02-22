/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {string} traversal
 * @return {TreeNode}
 */
var recoverFromPreorder = function(traversal) {
    let n = traversal.length;
    let idx = 0;

    const buildTree = (depth) => {
        if(idx >= n) return null;

        let countDashes = 0;
        while(idx < n && traversal[idx] === '-') {
            countDashes++;
            idx++;
        }

        if(countDashes !== depth) {
            idx -= countDashes;
            return null;
        }

        let val = 0;
        while(idx < n && /\d/.test(traversal[idx])) {
            val = val * 10 + (traversal[idx] - '0');
            idx++;
        }

        let node = new TreeNode(val);
        node.left = buildTree(depth + 1);
        node.right = buildTree(depth + 1);

        return node;
    }

    return buildTree(0);
};
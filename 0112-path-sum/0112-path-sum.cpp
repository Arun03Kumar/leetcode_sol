/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode *root, int target, int curr) {
        if(!root) return false;
        curr += root -> val;

        if(root -> left == nullptr && root -> right == NULL) {
            if(target == curr) return true;
            return false;
        }
               
        bool x = helper(root -> left, target, curr);
        bool y = helper(root -> right, target, curr);

        return x || y;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return helper(root, targetSum, 0);
    }
};
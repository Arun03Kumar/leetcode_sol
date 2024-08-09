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
    int helper(TreeNode *root) {
        if(!root) return -1;

        int left = helper(root -> left);
        if(left == -1) return root -> val;

        int right = helper(root -> right);

        if(root -> val == 2) return left || right;
        else return left && right;
    }
    bool evaluateTree(TreeNode* root) {
        return helper(root);
    }
};
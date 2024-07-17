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
    void helper(TreeNode *root) {
        if(root == nullptr) return;

        helper(root -> left);
        helper(root -> right);

        TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;        
    }

    TreeNode* invertTree(TreeNode* root) {
        // do a post order traversal and when you came back to root then swap its left and right childrens 

        if(!root) return root;
        helper(root);
        return root;
    }
};
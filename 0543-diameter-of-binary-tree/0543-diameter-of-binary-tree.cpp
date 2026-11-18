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
    int height(TreeNode *root) {
        if(root == NULL) return 0;

        int l = height(root -> left);
        int r = height(root -> right);

        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL) return 0;
        
        int h_left = height(root -> left);
        int h_right = height(root -> right);

        int di_left = diameterOfBinaryTree(root -> left);
        int di_right = diameterOfBinaryTree(root -> right);

        return max(h_left + h_right, max(di_left, di_right));

    }
};
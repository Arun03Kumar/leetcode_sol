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
    void inorder_traversal(TreeNode *root, vector<int> &v) {
        if(!root) return;

        inorder_traversal(root -> left, v);
        v.push_back(root -> val);
        inorder_traversal(root -> right, v);

    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inorder_traversal(root, inorder);

        for(int i = 1; i < inorder.size(); i++) {
            if(inorder[i] <= inorder[i - 1]) return false;
        }

        return true;
    }
};
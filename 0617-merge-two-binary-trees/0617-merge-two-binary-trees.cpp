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
    TreeNode *helper(TreeNode *root1, TreeNode *root2) {
        if(root1 == nullptr && root2 == nullptr) return nullptr;

        TreeNode *root;
        if(root1 && root2) {
            root = new TreeNode(root1 -> val + root2 -> val);
        }
        else if(root1 && root2 == nullptr) {
            root = new TreeNode(root1 -> val);
        }
        else {
            root = new TreeNode(root2 -> val);
        }

        root -> left = helper(root1 ? root1 -> left : nullptr, root2 ? root2 -> left : NULL);
        root -> right = helper(root1 ? root1 -> right : nullptr, root2 ? root2 -> right : NULL);

        return root;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return helper(root1, root2);
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) {
            return nullptr;
        }

        if(root == p || root == q) {
            return root;
        }

        TreeNode *left_ans = lowestCommonAncestor(root -> left, p, q);
        TreeNode *right_ans = lowestCommonAncestor(root -> right, p, q);

        if(left_ans != nullptr && right_ans != nullptr) {
            return root;
        }

        if(left_ans != nullptr) {
            return left_ans;
        }

        return right_ans;
    }
};
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
    TreeNode* prev = nullptr;
    void helper(TreeNode *root, int &ans) {
        if(!root) return;

        helper(root -> left, ans);
        if(prev) {
            ans = min(ans, abs(root -> val - prev -> val));
        }
        prev = root;
        // if(root -> right)
        helper(root -> right, ans);
    }

    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        helper(root, ans);
        return ans;
    }
};
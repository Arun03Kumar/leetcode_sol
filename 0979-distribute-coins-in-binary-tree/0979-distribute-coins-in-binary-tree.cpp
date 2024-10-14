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
    int dfs(TreeNode *root, int &ans) {
        if(!root) return 0;

        int left = dfs(root -> left, ans);
        int right = dfs(root -> right, ans);

        ans += abs(left) + abs(right);

        return root -> val + left + right - 1;
    }
    int distributeCoins(TreeNode* root) {
        // for each node we can ask from its left and right subtree that how much extra coins they have
        // if any node has x coins then it will return x-1 to its parent
        // so if node has 0 coins then it will return -1 to its parent it means it requires one coin
        // means one move should be needed to supply the coin
        // so for each node we can add the abs values from left and right

        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
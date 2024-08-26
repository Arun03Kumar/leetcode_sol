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
    void DFS(TreeNode *root, int curr_max, int &ans) {
        if(!root) return;

        if(root -> val >= curr_max) ans++;

        DFS(root -> left, max(root -> val, curr_max), ans);
        DFS(root -> right, max(root -> val, curr_max), ans);
    }

    int goodNodes(TreeNode* root) {
        // just maintain a lowest value for till each node if the current node value is less than that value then it means it will be smaller to all other nodes in that path
        int ans = 0;
        DFS(root, root -> val, ans);
        return ans;
    }
};
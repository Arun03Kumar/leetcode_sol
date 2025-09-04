class Solution {
public:
    // Pass the tail pointer 'ans' by reference using the '&' symbol
    void solve(TreeNode *root, TreeNode* &ans) {
        if(!root) return;

        solve(root->left, ans);

        // Attach the new node to the current tail's right
        ans->right = new TreeNode(root->val);
        // CRITICAL FIX: Move the tail pointer forward to the newly added node
        ans = ans->right;

        solve(root->right, ans);
    }

    TreeNode* increasingBST(TreeNode* root) {
        // Create a dummy head to simplify building the new tree
        TreeNode *dummyHead = new TreeNode(-1);
        // 'tail' will point to the last node in the new tree
        TreeNode *tail = dummyHead;

        solve(root, tail);

        // The actual tree starts at the right of the dummy head
        return dummyHead->right;
    }
};
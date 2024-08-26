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

    bool solve(TreeNode *root, long long left, long long right) {
        if(!root) return true;
        if(root -> val <= left || root -> val >= right) return false;

        bool a = solve(root -> left, left, root -> val);
        bool b = solve(root -> right, root -> val, right);

        return a && b;
    }

    bool isValidBST(TreeNode* root) {
        // vector<int> inorder;
        // inorder_traversal(root, inorder);

        // for(int i = 1; i < inorder.size(); i++) {
        //     if(inorder[i] <= inorder[i - 1]) return false;
        // }

        // return true;


        // if we can provide a range to each node then we can compare if current node value lie within that range or not if not then it can't be a BST.
        // so we start with int min and int max for root
        // when we go left then range will shrink to the int min to root_val
        // similarly when we go right then range will shrink to root -> val to the int_max

        long long left = LONG_MIN;
        long long right = LONG_MAX;

        return solve(root, left, right);
    }
};
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
    void inorder_traversal(TreeNode *root, vector<int> &arr) {
        if(!root) return;
        inorder_traversal(root -> left, arr);
        arr.push_back(root -> val);
        inorder_traversal(root -> right, arr);
    }

    TreeNode* solve(vector<int> arr, int l, int r) {
        if(l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode *root = new TreeNode(arr[mid]);
        root -> left = solve(arr, l, mid - 1);
        root -> right = solve(arr, mid + 1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        // do an inorder traversal to get the sorted array then find mid and make this as a root and assign left subarray as left subtree and right subarray as right subtree.
    // with the help of recursion we can do it easily.
        vector<int> inorder;
        inorder_traversal(root, inorder);
        return solve(inorder, 0, inorder.size() - 1);
    }
};
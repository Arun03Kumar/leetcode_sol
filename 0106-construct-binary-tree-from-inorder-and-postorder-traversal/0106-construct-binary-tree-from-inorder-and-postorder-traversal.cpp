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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int in_start, int in_end, int post_start, int post_end) {

        if(in_start > in_end) return nullptr;

        TreeNode *root = new TreeNode(postorder[post_end]);
        
        int i = in_start;
        for(; i <= in_end; i++) {
            if(inorder[i] == root -> val) {
                break;
            }
        }

        int left_size = i - in_start;
        int right_size = in_end - i;

        root -> left = solve(inorder, postorder, in_start, i - 1, post_start, post_start + left_size - 1);
        root -> right = solve(inorder, postorder, i + 1, in_end, post_end - right_size, post_end - 1);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // we know that last index of postorder array will contain the root of the tree
        // so when we get the root we need to find the left subtree and right subtree
        // with the help of indexings we can get the required positions
        // for each recursive calls we need the left subtree and right subtree

        // we need 4 pointers in_start, in_end, post_start, post_end
        // we search the post_end value in inorder array
        // so starting from in_start to that index will become the left subtree and and i + 1 to in_end will become the right subtree
        // we can find the number of elements in the left and right subtree 
        // so in left subtree we send post_start and post_start + left_size
        // in for right child we send post_end - right_size to post_end - 1
        
        int n = inorder.size();

        int in_start = 0, in_end = n - 1;
        int post_start = 0, post_end = n - 1;

        return solve(inorder, postorder, in_start, in_end, post_start, post_end);
    }
};
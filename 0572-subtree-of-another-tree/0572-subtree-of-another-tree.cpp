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
    bool solve(TreeNode *root, TreeNode *sub) {
        // now here we can check if two tree are equal
        if(root == nullptr && sub == nullptr) return true;

        // if both nodes are not nullptr then we can check if their value is same if not then we can directly return false
        // if yes then we can check on their left and right subtrees
        if(root && sub && root -> val == sub -> val) {
            bool a = solve(root -> left, sub -> left);
            bool b = solve(root -> right, sub -> right);
            return a && b;
        }

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // first we check if subroot is null it means it can be sub tree.
        // if it is not null then we check if original tree is null if it is then we can not find the subtree 
        //if both cases are false then we check if current node of original and current node of subtree give true result.
        // if not then we check on the left child of original tree, simillarly on the right subtree.

        if(subRoot == nullptr) return true;
        if(root == nullptr) return false;

        if(solve(root, subRoot)) return true;

        int left = isSubtree(root -> left, subRoot);
        int right = isSubtree(root -> right, subRoot);
        return left || right;
    }
};
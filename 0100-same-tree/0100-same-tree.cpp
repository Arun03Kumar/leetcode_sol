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
    bool helper(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p -> val == q -> val) {
            bool x = isSameTree(p -> left, q -> left);
            bool y = isSameTree(p -> right, q -> right);
            return x && y;
        }
        else {
            return false;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // check if both nodes are null pointer then it is valid but if only one is null pointer then it is invalid
        return helper(p, q);
    }
};
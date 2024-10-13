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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        // we don't need to actually flip the tree to get the solution
        // we can check if tree is equivalent without flip or equivalnet with the swap if left and right subtree, if in any case we get true answer is true;

        // if both the roots are null it means they are equivalent
        // if one root is null and other is not it means they are not equivalent

        if(root1 == nullptr && root2 == nullptr) return true;
        if((root1 == nullptr && root2 != nullptr) || (root1 != nullptr && root2 == nullptr)) return false;

        if(root1 -> val != root2 -> val) return false;

        bool a = flipEquiv(root1 -> left, root2 -> left);
        bool b = flipEquiv(root1 -> right, root2 -> right);

        bool c = flipEquiv(root1 -> left, root2 -> right);
        bool d = flipEquiv(root1 -> right, root2 -> left);

        return (a && b) || (c && d);
    }
};
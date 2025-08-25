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
    TreeNode* solve(vector<int> &postorder, int &postorderIdx, int subtreeStartIdx, int subtreeEndIdx, unordered_map<int, int> &mp) {
        if(subtreeStartIdx > subtreeEndIdx) return nullptr;

        int rootVal = postorder[postorderIdx];
        TreeNode* root = new TreeNode(rootVal);

        postorderIdx--;

        int inorderRootIdx = mp[rootVal];

        root -> right = solve(postorder, postorderIdx, inorderRootIdx + 1, subtreeEndIdx, mp);
        root -> left = solve(postorder, postorderIdx, subtreeStartIdx, inorderRootIdx - 1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int postorderIdx = postorder.size() - 1;
        return solve(postorder, postorderIdx, 0, postorder.size() - 1, mp);
    }
};
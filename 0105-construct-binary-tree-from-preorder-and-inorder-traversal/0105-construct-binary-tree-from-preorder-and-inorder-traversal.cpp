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
    TreeNode* solve(vector<int> &preorder, int &preorderIdx, int inorderLeftIdx, int inorderRightIdx, unordered_map<int, int> &mp) {
        if(inorderLeftIdx > inorderRightIdx) return nullptr;

        int rootVal = preorder[preorderIdx];
        TreeNode *root = new TreeNode(rootVal);

        preorderIdx++;

        int inorderRootIdx = mp[rootVal];

        root -> left = solve(preorder, preorderIdx, inorderLeftIdx, inorderRootIdx - 1, mp);
        root -> right = solve(preorder, preorderIdx, inorderRootIdx + 1, inorderRightIdx, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int preorderIdx = 0;
        return solve(preorder, preorderIdx, 0, inorder.size() - 1, mp);
    }
};
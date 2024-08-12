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
    void helper(TreeNode *root, vector<int> &ans, int level) {
        if(!root) return;

        if(ans.size() < level) {
            ans.push_back(root -> val);
        }

        helper(root -> right, ans, level + 1);
        helper(root -> left, ans, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        // Approach 1: DFS
        // in this we are checking the ans array size and the level, because in the ans array we will have elements equal to the level.
        // but in the recursion call we will go to the right first.
        // before inserting in ans check if size of ans is less than the current level.
        // because when recursion will return the level size will be decreased but ans will be updated.
        vector<int> ans;
        helper(root, ans, 1);
        return ans;
    }
};
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
    vector<TreeNode*> recursion(int start, int end) {
        if(start > end) return {nullptr};

        if(start == end) return {new TreeNode(start)};

        vector<TreeNode*> ans;
        for(int i = start; i <= end; i++) {
            vector<TreeNode*> left_bsts = recursion(start, i - 1);
            vector<TreeNode*> right_bsts = recursion(i + 1, end);

            for(TreeNode* left_bst : left_bsts) {
                for(TreeNode* right_bst : right_bsts) {

                    TreeNode *root = new TreeNode(i);
                    root -> left = left_bst;
                    root -> right = right_bst;

                    ans.push_back(root);

                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        // we are creating all the bsts present on the left side and on right side
        // then creating every combination of left and right
        // means if we fix the left subtree then we can attach every right  subtree to the root and we are storing the root 
        return recursion(1, n);
    }
};
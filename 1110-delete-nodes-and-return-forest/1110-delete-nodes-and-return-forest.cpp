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
    TreeNode* delete_helper(TreeNode* root, unordered_set<int> &st, vector<TreeNode*> &ans) {
        if(root == nullptr) return nullptr;

        root -> left = delete_helper(root -> left, st, ans);
        root -> right = delete_helper(root -> right, st, ans);

        if(st.find(root -> val) != st.end()) {

            if(root -> left != nullptr) {
                ans.push_back(root -> left);
            }

            if(root -> right != nullptr) {
                ans.push_back(root -> right);
            }

            return nullptr;
        }
        else {

            return root;

        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // start from bottom of the tree and find if that node should be deleted, if yes then return null to the parent and store that node in answer;
        // for searching we added elements in to unordered set.
        // 

        vector<TreeNode*> ans;

        unordered_set<int> st;
        for(auto x: to_delete) {
            st.insert(x);
        }

        delete_helper(root, st, ans);

        if(st.find(root -> val) == st.end()) {
            ans.push_back(root);
        }

        return ans;
    }
};
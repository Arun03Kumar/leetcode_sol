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
    void helper(TreeNode *root, vector<int> &ans) {
        if(root == nullptr) return;

        helper(root -> left, ans);
        ans.push_back(root -> val);
        helper(root -> right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // helper(root, ans);

        // return ans;

        // Approach 2: using stack;

        stack<TreeNode*> st;
        vector<int> ans;

        TreeNode *temp = root;

        while(true) {
            if(temp != nullptr) {
                st.push(temp);
                temp = temp -> left;
            }
            else {
                if(st.empty()) break;

                TreeNode *top = st.top();
                ans.push_back(top -> val);
                st.pop();
                temp = top -> right;;
            }
        }

        return ans;
    }
};
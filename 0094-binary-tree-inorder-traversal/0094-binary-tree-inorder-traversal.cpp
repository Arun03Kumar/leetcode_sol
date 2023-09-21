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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* current = root;
        while(true) {
            if(current != NULL) {
                s.push(current);
                current = current -> left;
            } else{
                if(s.empty()) break;
                else {
                    TreeNode* top = s.top();
                    s.pop();
                    ans.push_back(top -> val);
                    current = top -> right;
                }
            }
        }
        return ans;
    }
};
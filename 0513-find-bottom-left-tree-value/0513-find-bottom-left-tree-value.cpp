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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;
        while(!q.empty()) {
            TreeNode *front = q.front();
            q.pop();

            if(front -> right != nullptr) {
                q.push(front -> right);
            }

            if(front -> left != nullptr) {
                q.push(front -> left);
            }

            if(front -> left == nullptr && front -> right == nullptr) {
                ans = front -> val;
            }
        }

        return ans;
    }
};
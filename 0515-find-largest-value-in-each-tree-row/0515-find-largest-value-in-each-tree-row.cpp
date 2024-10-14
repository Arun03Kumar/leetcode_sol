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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            int max_tmp = INT_MIN;

            while(size--) {

                TreeNode* front = q.front();
                q.pop();
                max_tmp = max(max_tmp, front -> val);

                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }

            ans.push_back(max_tmp);
        }

        return ans;
    }
};
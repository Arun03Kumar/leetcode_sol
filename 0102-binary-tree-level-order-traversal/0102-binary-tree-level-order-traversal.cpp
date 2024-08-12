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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        priority_queue<TreeNode*, vector<TreeNode*>, greater<TreeNode*>> pq;
        
        pq.push(root);

        while(!pq.empty()) {
            int size = pq.size();
            vector<int> temp;
            while(size--) {
                TreeNode *top = pq.top();
                pq.pop();

                if(top) {
                    temp.push_back(top -> val);
                }

                if(top -> left) pq.push(top -> left);
                if(top -> right) pq.push(top -> right);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
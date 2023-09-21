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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp(size);
            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if(flag == 0) {
                    if(front)
                    temp[i] = front -> val;
                } 
                if(flag == 1) {
                    // int idx = size - i - 1;
                    // cout << idx << " ";
                    if(front)
                    temp[size - 1 - i] = front -> val;
                }
                if(front && front -> left) q.push(front -> left); 
                if(front && front -> right) q.push(front -> right);

               
            }
             if(flag == 0) flag = 1;
                else if(flag == 1) flag = 0; 
            ans.push_back(temp);
        }
        return ans;
    }
};
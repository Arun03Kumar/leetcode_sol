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
    TreeNode* solve(TreeNode* root, int level) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;

        while(!q.empty()) {
            int size = q.size();
            vector<TreeNode*> temp;
            while(size--) {
                TreeNode *front = q.front();
                q.pop();

                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);

                if(count % 2 == 1) temp.push_back(front);

            }

            if(count % 2 == 1) {
                int l = 0, r = temp.size() - 1;
                while(l <= r) {
                    int x = temp[l] -> val;
                    temp[l] -> val = temp[r] -> val;
                    temp[r] -> val = x;

                    l++;
                    r--;
                }
            }

            count++;
        }

        return root;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        return solve(root, 0);
    }
};
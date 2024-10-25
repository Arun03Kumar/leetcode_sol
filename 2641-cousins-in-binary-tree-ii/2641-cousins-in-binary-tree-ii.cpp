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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // Approach 1: using BFS
        // we can find total sum of each level with BFS
        // then if we can delete the sibling sum from the current level sum for each node at that level we can find the cousin sum
        // to find the sibling sum we can do again bfs and then we can access the both childrens of the current node then this way we can update the childrens and we can access the next level sum 

        queue<TreeNode*> q;
        q.push(root);
        vector<int> level_sum;

        while(!q.empty()) {
            int curr_level_sum = 0;

            int size = q.size();

            while(size--) {
                TreeNode *front = q.front();
                q.pop();

                curr_level_sum += front -> val;
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }

            level_sum.push_back(curr_level_sum);
        }

        q.push(root);
        root -> val = 0;

        int idx = 1;

        while(!q.empty()) {

            int size = q.size();
            while(size--) {

                TreeNode *front = q.front();
                q.pop();

                int sibling_sum = front -> left ? front -> left -> val : 0;
                sibling_sum += front -> right ? front -> right -> val : 0;

                // int next_level_sum; = idx < level_sum.size() ? level_sum[idx];

                if(front -> left) {
                    front -> left -> val = level_sum[idx] - sibling_sum;
                    q.push(front -> left);
                }

                if(front -> right) {
                    front -> right -> val = level_sum[idx] - sibling_sum;
                    q.push(front -> right);
                }

            }
            idx++;

        }

        return root;

    }
};
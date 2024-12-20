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
    TreeNode* bfs(TreeNode* root, int level) {
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

    void dfs(TreeNode *node1, TreeNode *node2, int level) {
        if(!node1 || !node2) return;

        if(level % 2 == 1) {
            int x = node1 -> val;
            node1 -> val = node2 -> val;
            node2 -> val = x;
        }

        dfs(node1 -> left, node2 -> right, level + 1);
        dfs(node1 -> right, node2 -> left, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        // return bfs(root, 0);


        // Approach 2: dfs
        // we can send two nodes in the function which are like left and right pointers
        // and then swap val in left and right pointers as we did in bfs case
        dfs(root -> left, root -> right, 1);
        return root;
    }
};
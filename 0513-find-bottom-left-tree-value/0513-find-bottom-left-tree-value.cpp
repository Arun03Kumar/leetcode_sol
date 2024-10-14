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
    void dfs(TreeNode *root, int curr_depth, int &max_depth, int &ans) {
        if(!root) return;

        if(curr_depth > max_depth) {
            max_depth = curr_depth;
            ans = root -> val;
        }

        dfs(root -> left, curr_depth + 1, max_depth, ans);
        dfs(root -> right, curr_depth + 1, max_depth, ans);
    }

    int findBottomLeftValue(TreeNode* root) {
        // Approach 1: DFS
        // at each dfs call we check if current dpepth is greater than the previous depth the first call will always be the left most hence we need not to worry about.
        int ans = 0;
        int max_depth = -1;
        dfs(root, 0, max_depth, ans);
        return ans;

        // queue<TreeNode*> q;
        // q.push(root);

        // int ans = 0;
        // while(!q.empty()) {
        //     TreeNode *front = q.front();
        //     q.pop();

        //     if(front -> right != nullptr) {
        //         q.push(front -> right);
        //     }

        //     if(front -> left != nullptr) {
        //         q.push(front -> left);
        //     }

        //     if(front -> left == nullptr && front -> right == nullptr) {
        //         ans = front -> val;
        //     }
        // }

        // return ans;
    }
};
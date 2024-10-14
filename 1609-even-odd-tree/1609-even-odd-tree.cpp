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
    bool dfs(TreeNode *root, int level, vector<int> &max_at_level) {
        if(!root) return true;

        if(level == max_at_level.size()) {
            if(level % 2 == 0 && root -> val % 2 == 0) return false;
            if(level % 2 != 0 && root -> val % 2 != 0) return false;

            max_at_level.push_back(root -> val);
        }
        else {
            if(level % 2 == 0) {
                if(root -> val % 2 == 0 || root -> val <= max_at_level[level]) return false;
                else max_at_level[level] = root -> val;
            }
            else {
                if(root -> val % 2 != 0 || root -> val >= max_at_level[level]) return false;
                else max_at_level[level] = root -> val;
            }
        }

        bool left = dfs(root -> left, level + 1, max_at_level);
        bool right = dfs(root -> right, level + 1, max_at_level);

        return left && right;
    }

    bool isEvenOddTree(TreeNode* root) {
        vector<int> max_at_level;
        return dfs(root, 0, max_at_level);
    }
};
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
    int solve(TreeNode *root, int curr) {
        if(root == nullptr) {
            return 0;
        }

        int num = curr * 10 + root -> val;

        if(root -> left == nullptr && root -> right == nullptr) {
            return num;
        }

        int left_sum = solve(root -> left, num);
        int right_sum = solve(root -> right, num);

        return left_sum + right_sum;
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};
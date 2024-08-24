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
    bool isCompleteTree(TreeNode* root) {
        // Approach 1: BFS
        // take a variable which stores that is a null value is seen in the past or not if yes then return false.

        queue<TreeNode*> q;
        q.push(root);

        bool past = false;

        while(!q.empty()) {

            TreeNode *front = q.front();
            q.pop();

            if(front == nullptr) {
                past = true;
            }
            else {

                if(past == true) return false;

                q.push(front -> left);
                q.push(front -> right);

            }
        }

        return true;

    }
};
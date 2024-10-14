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
    void dfs(TreeNode *root, string curr, string &ans) {
        if(!root) return;

        curr += 'a' + root -> val;

        if(!root -> left && !root -> right) {
            string temp = curr;
            reverse(begin(temp), end(temp));

            if(ans == "") ans = temp;
            else {
                if(temp < ans) {
                    ans = temp;
                }
            }
        }

        dfs(root -> left, curr, ans);
        dfs(root -> right, curr, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        dfs(root, "", ans);
        return ans;
    }
};
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
    string helper(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*> &ans) {
        if(!root) return "N";

        string l = helper(root -> left, mp, ans);
        string r = helper(root -> right, mp, ans);

        string s = to_string(root -> val) + "," + l + "," + r;

        if(mp[s] == 1) {
            ans.push_back(root);
        }
        mp[s]++;

        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // for each node create a string and find if it is present already in the map.
        // to create the string also use null value to get the unique string values for each subtree.
        unordered_map<string, int> mp;
        vector<TreeNode*> ans;
        helper(root, mp, ans);
        return ans;
    }
};
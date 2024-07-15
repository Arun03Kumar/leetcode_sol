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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> ump;
        unordered_set<int> is_child;

        for(auto x: descriptions) {
            int par = x[0];
            int child = x[1];
            int is_left = x[2];

            if(ump.find(par) == ump.end()) {
                ump[par] = new TreeNode(par);
            }

            if(ump.find(child) == ump.end()) {
                ump[child] = new TreeNode(child);
            }

            if(is_left) {
                ump[par] -> left = ump[child];
            }
            else {
                ump[par] -> right = ump[child];
            }

            is_child.insert(child);
        }

        for(auto x: descriptions) {
            int par = x[0];
            if(is_child.find(par) == is_child.end()) {
                return ump[par];
            }
        }

        return nullptr;
    }
};
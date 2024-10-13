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
    int recursion(TreeNode *root, bool flag) {
        if(root == nullptr) return 0;

        int take = 0, skip = 0;
        if(flag) {
            take = root -> val + recursion(root -> left, !flag) + recursion(root -> right, !flag);     
            skip = recursion(root -> left, flag) + recursion(root -> right, flag);  
        }
        else {
            skip = recursion(root -> left, !flag) + recursion(root -> right, !flag); 
        }
        
        

        return max(take, skip);
    }

    int memoization(TreeNode* root, int flag, map<pair<TreeNode*, bool>, int> &mp) {
        if(root == nullptr) return 0;

        if(mp.find({root, flag}) != mp.end()) return mp[{root, flag}];

        int take = 0, skip = 0;

        if(flag) {
            take = root -> val + memoization(root -> left, !flag, mp) + memoization(root -> right, !flag, mp);
            skip = memoization(root -> left, flag, mp) + memoization(root -> right, flag, mp);
        }
        else {
            skip = memoization(root -> left, !flag, mp) + memoization(root -> right, !flag, mp);
        }

        return mp[{root, flag}] = max(take, skip);
    }

    int rob(TreeNode* root) {
        // return recursion(root, 1);

        map<pair<TreeNode*, bool>, int> mp;
        return memoization(root, 1, mp);
    }
};
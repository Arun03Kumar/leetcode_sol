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
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int> mp) {
        // Base case 1: If the range is empty, there is no node.
        if (preStart > preEnd) {
            return nullptr;
        }

        // 1. The first element in the preorder range is the root of the current subtree.
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        // Base case 2: If there's only one element, it's a leaf node. Return it.
        if (preStart == preEnd) {
            return root;
        }

        // 2. The next element in preorder is the root of the left subtree.
        int leftSubtreeRootVal = preorder[preStart + 1];
        
        // 3. Find the index of the left subtree's root in the postorder traversal.
        int leftSubtreeEndIndexPost = mp[leftSubtreeRootVal];
        
        // 4. Calculate the number of nodes in the left subtree.
        int leftSubtreeSize = leftSubtreeEndIndexPost - postStart + 1;

        // 5. Recursively build the left and right subtrees.
        // Left child:
        root->left = solve(preorder, preStart + 1, preStart + leftSubtreeSize, postorder, postStart, leftSubtreeEndIndexPost, mp);
        
        // Right child:
        root->right = solve(preorder, preStart + leftSubtreeSize + 1, preEnd, postorder, leftSubtreeEndIndexPost + 1, postEnd - 1, mp);

        return root;
    }


    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[postorder[i]] = i;
        }
        return solve(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
    }
};

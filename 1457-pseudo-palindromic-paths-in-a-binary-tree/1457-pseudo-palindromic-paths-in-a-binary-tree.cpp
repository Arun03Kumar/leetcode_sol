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
    void recursion(TreeNode *root, int &ans, vector<int> &freq) {
        if(!root) {
            return;
        }

        freq[root -> val]++;

        if(!root -> left && !root -> right) {
            int odd = 0;
            for(int &x: freq) {
                if(x % 2 != 0) odd++;
            }

            if(odd <= 1) ans++;
        }

        recursion(root -> left, ans, freq);
        recursion(root -> right, ans, freq);

        freq[root -> val]--;

    }

    int pseudoPalindromicPaths (TreeNode* root) {
        // Approach 1:
        // we can make palindrome if and only if each element is even and there is no odd frequency element or if present then there should be only one such element
        // so we can maintain a 10 size array and count the frequency of each element
        // when we hit a leaf node then the frequency array will give the frequency of each element in the path
        // if number of odd elements are greater than 1 then we can not make a palindrome
        
        int ans = 0;
        vector<int> freq(10, 0);
        recursion(root, ans, freq);
        return ans;
    }
};
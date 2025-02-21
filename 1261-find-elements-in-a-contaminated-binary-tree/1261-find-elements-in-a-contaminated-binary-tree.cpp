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
class FindElements {
public:
    TreeNode *head;
    FindElements(TreeNode* root) {
        head = root;
        head -> val = 0;
        dfs(head);
    }

    void dfs(TreeNode *root) {
        if(root == nullptr) return;

        if(root -> left) {
            root -> left -> val = 2 * root -> val + 1;
            dfs(root -> left);
        }
        if(root -> right) {
            root -> right -> val = 2 * root -> val + 2;
            dfs(root -> right);
        }
        
    }
    
    bool inorder(TreeNode *root, int n) {
        if(!root) return false;

        if(root -> val == n) return true;
        return inorder(root -> left, n) || inorder(root -> right, n);
    }

    bool find(int target) {
        return inorder(head, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
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
class BSTIterator {
public:
    vector<int> inorder;
    int i;
    BSTIterator(TreeNode* root) {
        inorder_traversal(root, inorder);
        i = -1;
    }

    void inorder_traversal(TreeNode *root, vector<int> &inorder) {
        if(!root) return;
        
        inorder_traversal(root -> left, inorder);
        inorder.push_back(root -> val);
        inorder_traversal(root -> right, inorder);
    }
    
    int next() {
        return inorder[++i];
    }
    
    bool hasNext() {
       if(i + 1 < inorder.size()) return true;
       return false; 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
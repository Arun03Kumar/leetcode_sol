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
    int count_nodes(TreeNode *root) {
        if(root == nullptr) return 0;

        int left = count_nodes(root -> left);
        int right = count_nodes(root -> right);

        return left + right + 1;
    }

    bool is_complete_tree(TreeNode *root, int idx, int total_nodes) {
        if(root == nullptr) return true;
        if(idx > total_nodes) return false;

        bool left = is_complete_tree(root -> left, 2 * idx, total_nodes);
        bool right = is_complete_tree(root -> right, 2 * idx + 1, total_nodes);

        return (left && right);
    }

    bool isCompleteTree(TreeNode* root) {
        // Approach 1: BFS
        // take a variable which stores that is a null value seen in the past or not if yes then return false.

        // queue<TreeNode*> q;
        // q.push(root);

        // bool past = false;

        // while(!q.empty()) {

        //     TreeNode *front = q.front();
        //     q.pop();

        //     if(front == nullptr) {
        //         past = true;
        //     }
        //     else {

        //         if(past == true) return false;

        //         q.push(front -> left);
        //         q.push(front -> right);

        //     }
        // }

        // return true;



        // Approach 2: DFS
        // we know if we start the indexing of root node from 1 then left child can be represented as 2*i and right child can be represented as 2*i+1
        // so if the any childs index is greater than the total number of nodes in the tree then it wont be a complete binary tree
        // see with the examples.

        int total_nodes = count_nodes(root);
        return is_complete_tree(root, 1, total_nodes);
    }
};
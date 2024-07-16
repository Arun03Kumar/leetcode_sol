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
    TreeNode* LCA(TreeNode *root, int startValue, int destValue) {
        if(root == nullptr) return nullptr;

        if(root -> val == startValue || root -> val == destValue) {
            return root;
        }

        TreeNode* left_ans = LCA(root -> left, startValue, destValue);
        TreeNode* right_ans = LCA(root -> right, startValue, destValue);

        if(left_ans != nullptr && right_ans != nullptr) return root;

        if(left_ans != nullptr) return left_ans;

        return right_ans;
    }

    bool find_path(TreeNode *lca_node, int target, string &path) {
        if(lca_node == nullptr) return false;

        if(lca_node -> val == target) return true;

        // explore left
        path.push_back('L');
        bool found_on_left = find_path(lca_node -> left, target, path);
        if(found_on_left) return true;

        path.pop_back();

        // else search in right subtree but before that pop the last element from the path

        //explore right
        path.push_back('R');
        bool found_on_right = find_path(lca_node -> right, target, path);
        if(found_on_right) return true;

        path.pop_back();

        return false;

    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Approach 1: USING LCA
        // first find the lca node then find path from lca to the start
        // then find path from lca to the dest node
        // we know from start to lca we have to move upwards always hence for all character in the path from lca to start we replace with U.
        
        TreeNode *LCA_node = LCA(root, startValue, destValue);

        string lca_to_start = "";
        string lca_to_dest = "";

        find_path(LCA_node, startValue, lca_to_start);
        find_path(LCA_node, destValue, lca_to_dest);

        string ans = "";

        for(char x: lca_to_start) {
            ans += 'U';
        }

        ans += lca_to_dest;

        return ans;
    }
};
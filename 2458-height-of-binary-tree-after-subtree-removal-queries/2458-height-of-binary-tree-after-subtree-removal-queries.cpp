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
    int find_height(TreeNode *root, int level, vector<int> &l, vector<int> &h, vector<int> &max_h_l, vector<int> &sec_max_h_l) {
        if(!root) return 0;

        l[root -> val] = level;

        int left_h = find_height(root -> left, level + 1, l, h, max_h_l, sec_max_h_l);
        int right_h = find_height(root -> right, level + 1, l, h, max_h_l, sec_max_h_l);

        h[root -> val] = max(left_h, right_h) + 1;

        if(h[root -> val] > max_h_l[level]) {
            sec_max_h_l[level] = max_h_l[level];
            max_h_l[level] = h[root -> val];
        }
        else if(h[root -> val] > sec_max_h_l[level]) {
            sec_max_h_l[level] = h[root -> val];
        }

        return h[root -> val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // we can store the level of each node in a seperate array and height of each node in a seperate array
        // then we can find the level of given query and then find the max height node in that level
        // we can also store the max height and second max height node for each level, because it may possible that in query we delete the heighest node so we want to return the 2nd heightst node
        // if node other than heighest is deleted then we can simply send the heighest node value

        vector<int> level(100001);
        vector<int> height(100001);
        vector<int> max_height_at_level(100001);
        vector<int> sec_max_height_at_level(100001);

        find_height(root, 0, level, height, max_height_at_level, sec_max_height_at_level);

        vector<int> ans;

        for(int &node: queries) {
            int level_of_node = level[node];
            int max_height_at_that_level = max_height_at_level[level_of_node];
            int sec_max_height_at_that_level = sec_max_height_at_level[level_of_node];
            int height_of_that_node = height[node];
            

            // to calculate the height we can find the level of the node then add the heighest height value this will give number of nodes in the heighest path, so if we subtract 1 from that it will give the number of edges
            if(height_of_that_node == max_height_at_that_level) {
                int temp = level_of_node + sec_max_height_at_that_level - 1;
                ans.push_back(temp);
            }
            else {
                int temp = level_of_node + max_height_at_that_level - 1;
                ans.push_back(temp);
            }
        }

        return ans;
    }
};
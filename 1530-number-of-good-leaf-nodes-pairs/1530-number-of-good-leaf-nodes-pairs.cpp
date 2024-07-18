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
    void make_graph_by_traversal(TreeNode* root, TreeNode* prev,  unordered_map<TreeNode*, vector<TreeNode*>> &adj, unordered_set<TreeNode*> &leaf_nodes) {
        if(root == nullptr) return;

        if(root -> left == nullptr && root -> right == nullptr) {
            leaf_nodes.insert(root);
        }

        if(prev != NULL) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        make_graph_by_traversal(root -> left, root, adj, leaf_nodes);
        make_graph_by_traversal(root -> right, root, adj, leaf_nodes);
    }
    int countPairs(TreeNode* root, int distance) {
        // first we create a graph out of given tree ans store the leaf node
        // then we do bfs from each node to each node for finding shortest distance
        // we do level wise traversal beacause if we go level grater than distance then we won't find our answer.
        // if leaf 1 to leaf 2 is good then leaf 2 to leaf 1 will also be good hence we divide our count by 2 because same distance is added twice.

        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> leaf_nodes;

        make_graph_by_traversal(root, NULL, adj, leaf_nodes);

        int count = 0;

        for(auto leaf: leaf_nodes) {
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;

            q.push(leaf);
            visited.insert(leaf);

            for(int level = 0; level <= distance; level++) {

                int N = q.size();
                while(N--) {

                    TreeNode* front = q.front();
                    q.pop();

                    if(front != leaf && leaf_nodes.find(front) != leaf_nodes.end()) {
                        count++;
                    }

                    for(auto x: adj[front]) {

                        if(visited.find(x) == visited.end()) {

                            q.push(x);
                            visited.insert(x);

                        }

                    }

                }

            }
        }

        return count / 2;
    }
};
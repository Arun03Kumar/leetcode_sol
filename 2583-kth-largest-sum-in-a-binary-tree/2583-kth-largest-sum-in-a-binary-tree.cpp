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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        q.push(root);

        while(!q.empty()) {

            int size = q.size();
            long long temp = 0;

            while(size--) {
                TreeNode *front = q.front();
                q.pop();

                temp += front -> val;

                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }

            cout << temp << " ";
            
            pq.push(temp);
            if(pq.size() > k) pq.pop();

        }

        return pq.size() < k ? -1 : pq.top();
    }
};
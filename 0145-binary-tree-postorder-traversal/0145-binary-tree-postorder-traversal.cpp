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
    vector<int> postorderTraversal(TreeNode* root) {
        // in post order what we do: we first to go left, left, left, left....
        // so if left is null then we check if top of stack contians right node, if it contains right node then we now go to left, left, left of this
        // if top of stack also doesn't contains the right then it means the top of node will go in to our answer.
        // and we also check if it is right child of top element because then top element would also go in answer next, because we have traversed left, right and now root.
        
        stack<TreeNode*> st;
        vector<int> ans;

        // if(root != nullptr) st.push(root);

        TreeNode* curr = root;

        while(curr != NULL || !st.empty()) {

            if(curr != nullptr) {

                st.push(curr);
                curr = curr -> left;

            }
            else {

                TreeNode *temp = st.top() -> right;

                if(temp == NULL) {

                    temp = st.top();
                    st.pop();
                    ans.push_back(temp -> val);

                    while(!st.empty() && temp == st.top() -> right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp -> val);
                    }

                }
                else {

                    curr = temp; 

                }

            }
        }

        return ans;
    }
};
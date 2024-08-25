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
        
        // Approach 1: using one stack
        // stack<TreeNode*> st;
        // vector<int> ans;

        // // if(root != nullptr) st.push(root);

        // TreeNode* curr = root;

        // while(curr != NULL || !st.empty()) {

        //     if(curr != nullptr) {

        //         st.push(curr);
        //         curr = curr -> left;

        //     }
        //     else {

        //         TreeNode *temp = st.top() -> right;

        //         if(temp == NULL) {

        //             temp = st.top();
        //             st.pop();
        //             ans.push_back(temp -> val);

        //             while(!st.empty() && temp == st.top() -> right) {
        //                 temp = st.top();
        //                 st.pop();
        //                 ans.push_back(temp -> val);
        //             }

        //         }
        //         else {

        //             curr = temp; 

        //         }

        //     }
        // }

        // return ans;




        // Approach 2: using two stacks
        // in this we first push the root in to first stack
        // then loop over till first stack is not empty
        // pop the top element then push in to 2nd stack
        // push the left child of popped element into stack1
        // push the right child of popped element into stack1;

        // when first stack empty pop all the elements from stack 2 and add into answer. that would be postorder traversal

        vector<int> ans;
        if(root == nullptr) return ans;
    
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()) {

            TreeNode *top = st1.top();
            st1.pop();
            st2.push(top);

            if(top -> left != nullptr) {
                st1.push(top -> left);
            }

            if(top -> right != nullptr) {
                st1.push(top -> right);
            }

        }

        while(!st2.empty()) {
            ans.push_back(st2.top() -> val);
            st2.pop();
        }

        return ans;

    }
};
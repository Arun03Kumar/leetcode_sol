/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        // if head is null then return null
        // if only one node then return that node
        // find the mid node using slow and fast algorithm
        // assign left nodes as left subtree and right nodes to the mid node as right subtree
        // make mid as root of the tree
        // but before assigning we need to break the left linked list else it will again traverse whole linked list
        if(head == nullptr) return NULL;

        if(!head -> next) return new TreeNode(head -> val);

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *slow_prev = NULL;

        while(fast != nullptr && fast -> next != nullptr) {
            slow_prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        TreeNode *root = new TreeNode(slow -> val);

        slow_prev -> next = NULL;
        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(slow -> next);

        return root;
    }
};
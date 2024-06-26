/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // 1. we can connect the child of a node by taking refrence of the parent, we take two pointers pointing at parent and left child, then we can add next of left child to the parent -> right, we refer parent as current_node.
        
        // 2. we can also connect the 5 in the example to the 6, because now we have connected 2 and 3 so when we are at 2, we can now also access the 6, because 2 -> next will point to 3 and 3 -> left will be 6, so when we are at any parent node we can check if its next pointer is not null, if it is not null then we can join, parent -> right -> next === parent -> next -> left.

        // here we initialsed next node to the left of root node, if it not present then we initialised with null pointer. 
        Node *current_node = root, *next_node = nullptr; // current_node points at parent node, next_node points at left child
        if(root) next_node = root -> left;
        while(root && next_node) {
            current_node -> left -> next = current_node -> right; // connecting left child to the right child
            if(current_node -> next) { // checking if next pointer points to a node
                current_node -> right -> next = current_node -> next -> left; // from example connecting node 5 to node 6
            }
            current_node = current_node -> next; // traversing to the next node in the same row, if it is not present then we take help of next_node and assing it to the current_node (going to node 3 from node 2 and after going to node 4 from the example).
            if(current_node == nullptr) {
                current_node = next_node;
                next_node = current_node -> left; // updating the next node so that we have the refrence.
            }
        }
        return root;
    }
};
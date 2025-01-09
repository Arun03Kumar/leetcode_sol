class Node {
public:
    Node *left;
    Node *right;
};

class Solution {
public:
    void insert(Node *root, int num) {
        Node *temp = root;

        for(int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;

            if(ith_bit == 0) {
                if(temp -> left == nullptr) {
                    temp -> left = new Node();
                }
                temp = temp -> left;
            }
            else {
                if(temp -> right == nullptr) {
                    temp -> right = new Node();
                }
                temp = temp -> right;
            }
        }
    }

    int max_xor(Node *root, int &num) {
        int max_x = 0;
        Node *temp = root;

        for(int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;

            if(ith_bit == 0) {
                if(temp -> right) {
                    max_x += pow(2, i);
                    temp = temp -> right;
                }
                else {
                    // max_x += pow(2, i) * 0;
                    temp = temp -> left;
                }
            }
            else {
                if(temp -> left) {
                    max_x += pow(2, i);
                    temp = temp -> left;
                }
                else {
                    // max_x += pow(2, i) * 0;
                    temp = temp -> right;
                }
            }
        }

        return max_x;
    }

    int findMaximumXOR(vector<int>& nums) {
        // using Trie
        // create a bit Trie, left node point to bit 0 and right node point to bit 1
        //to find the ith bit from msb we can right shift then take & with 1 if it is set then ith bit is 1 else 0 
        // this way we can create the Trie Structure
        // then we know that xor is maximum if both bits are different 
        // so during finding max xor with the x is we get ith bit as 0 then we want if we can get a 1 so we need to check in tree if we have a bit 1 if yes then at the same time we can calculate the xor value

        Node *root = new Node();    
        for(int &x: nums) {
            insert(root, x);
        }

        int ans = 0;
        for(int &x: nums) {
            int max_xor_with_x = max_xor(root, x);
            ans = max(ans, max_xor_with_x);
        }

        return ans;
    }
};
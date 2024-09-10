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
class Solution {
public:

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head -> next == nullptr) return head;

        ListNode *prev = head, *curr = head -> next;

        while(curr) {

            int n1 = prev -> val, n2 = curr -> val;
            int gcd = __gcd(n1, n2);

            ListNode *new_node = new ListNode(gcd);
            prev -> next = new_node;
            new_node -> next = curr;

            prev = new_node -> next;
            curr = curr -> next;
        }

        return head;
    }
};
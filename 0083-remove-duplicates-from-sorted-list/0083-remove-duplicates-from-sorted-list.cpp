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
    ListNode* deleteDuplicates(ListNode* head) {
        int num = -200;
        ListNode *temp, *prev;
        temp = prev = head;
        while(temp) {
            int currVal = temp -> val;
            while(prev -> next != NULL && prev -> next -> val == currVal) {
                prev = prev -> next;
            }
            temp -> next = prev -> next;
            temp = prev = prev -> next;
        }
        return head;
    }
};
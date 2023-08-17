/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = head;
        fast = head;
        do {
            if(slow && slow->next != nullptr) slow = slow->next;
            else slow = nullptr;
            if(fast && fast->next != nullptr && fast->next->next != nullptr) fast = fast->next->next;
            else fast = nullptr;
        } while(slow != nullptr && fast != nullptr && slow != fast);
        // while(fast != nullptr && slow != fast) {
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        if(fast == nullptr || slow == nullptr) return NULL;
        fast = head;
        while(slow && slow->next != nullptr && fast && fast->next != nullptr && slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
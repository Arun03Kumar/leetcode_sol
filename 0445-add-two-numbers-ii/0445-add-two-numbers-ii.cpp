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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        ListNode* temp = l1;
        while(temp != nullptr) {
            st1.push(temp -> val);
            temp = temp -> next;
        }
        temp = l2;
        while(temp != nullptr) {
            st2.push(temp -> val);
            temp = temp -> next;
        }

        // vector<int> ans;
        int carry = 0;
        ListNode* head = nullptr;

        while(!st1.empty() && !st2.empty()) {
            int a = st1.top();
            int b = st2.top();
            st1.pop();
            st2.pop();

            int sum = a + b + carry;
            carry = sum / 10;

            ListNode *temp = new ListNode(sum % 10);
            if(head == nullptr) head = temp;
            else {
                temp -> next = head;
                head = temp;
            }
        }

        while(!st1.empty()) {
            int a = st1.top();
            st1.pop();

            int sum = a + carry;
            carry = sum / 10;

            ListNode *temp = new ListNode(sum % 10);
            if(head == nullptr) head = temp;
            else {
                temp -> next = head;
                head = temp;
            }
        }

        while(!st2.empty()) {
            int a = st2.top();
            st2.pop();

            int sum = a + carry;
            carry = sum / 10;

            ListNode *temp = new ListNode(sum % 10);
            if(head == nullptr) head = temp;
            else {
                temp -> next = head;
                head = temp;
            }
        }

        if(carry > 0) {
            ListNode *temp = new ListNode(carry);
            if(head == nullptr) head = temp;
            else {
                temp -> next = head;
                head = temp;
            }  
        }

        return head;
    }
};
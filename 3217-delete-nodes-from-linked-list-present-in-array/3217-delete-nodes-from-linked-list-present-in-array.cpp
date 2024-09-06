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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> ump;
        for(int i = 0; i < nums.size(); i++) {
            ump[nums[i]]++;
        }  

        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *temp = dummy;

        while(temp -> next != nullptr) {
            int t_val = temp -> next -> val;
            if(ump.find(t_val) != ump.end()) {
                temp -> next = temp -> next -> next;
            }
            else {
                temp = temp -> next;
            }
        }

        return dummy -> next;
    }
};
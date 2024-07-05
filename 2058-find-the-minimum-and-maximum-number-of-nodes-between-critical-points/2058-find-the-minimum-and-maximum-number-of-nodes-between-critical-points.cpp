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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head, *curr = head -> next;
        int first_critical_pos = 0, prev_critical_pos = 0, min_dist = INT_MAX;
        int i = 1;
        while(curr -> next != nullptr) {
            if((curr -> val > curr -> next -> val && curr -> val > prev -> val) || (curr -> val < curr -> next -> val && curr -> val < prev -> val)) {
                if(first_critical_pos == 0) {
                    first_critical_pos = i;
                    prev_critical_pos = i;
                }
                else {
                    min_dist = min(min_dist, i - prev_critical_pos);
                    prev_critical_pos = i;
                }
            }
            i++;
            prev = curr;
            curr = curr -> next;
        }
        if(min_dist == INT_MAX) return {-1, -1};

        return {min_dist, prev_critical_pos - first_critical_pos};

    }
};
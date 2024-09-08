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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *temp = head;
        int size = 0;
        while(temp) {
            temp = temp -> next;
            size++;
        }
        vector<int> size_arr(k, size / k);
        for(int i = 0; i < size % k; i++) {
            size_arr[i]++;
        }

        for(int &x: size_arr) cout << x << " ";
        
        // int eq = size / k, rem = size % k;
        vector<ListNode*> ans(k, nullptr);

        temp = head;
        ListNode *prev = nullptr;

        for(int i = 0; i < k; i++) {
            ans[i] = temp;

            while(temp && size_arr[i]--) {
                prev = temp;
                temp = temp -> next;
            }
            if(prev) prev -> next = nullptr;
        }

        return ans;
    }
};
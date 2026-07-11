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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;
        int n = 0;

        while (tail && n < k) {
            tail = tail->next;
            n++;
        }

        if (n < k)
            return head;

        ListNode *prev = NULL;
        ListNode *curr = head;

        while (n--) {
            ListNode *next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }

        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
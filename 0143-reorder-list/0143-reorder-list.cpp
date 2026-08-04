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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        // Step 1: Find the middle
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode *second = slow->next;
        slow->next = nullptr;

        ListNode *prev = nullptr;
        while (second) {
            ListNode *next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // Step 3: Merge the two halves
        ListNode *first = head;
        second = prev;

        while (second) {
            ListNode *firstNext = first->next;
            ListNode *secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};
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
private:
    ListNode* findMiddle(ListNode *head) {
        if (!head || !head->next)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeList(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val <= l2->val) {
            l1->next = mergeList(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeList(l1, l2->next);
            return l2;
        }
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode *mid = findMiddle(head);

        ListNode *right = mid->next;
        mid->next = nullptr;

        // Recursively sort both halves
        ListNode *left = sortList(head);
        right = sortList(right);

        // Merge sorted halves
        return mergeList(left, right);
    }
};
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;

        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* prev = temp;

        while(head && head->next){
            ListNode* first = head;
            ListNode* second = head->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
            head = first->next;
        }
        return temp->next;
    }
};
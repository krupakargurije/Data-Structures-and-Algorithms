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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        
        int n = 0;
        ListNode *temp = head;

        while(temp){
            temp = temp->next;
            n++;
        }

        int half = (n / 2) - 1;
        temp = head;

        while(half--){
            temp = temp->next;
        }

        ListNode *curr = temp->next;
        temp->next = temp->next->next;
        delete curr;
        return head;
    }
};
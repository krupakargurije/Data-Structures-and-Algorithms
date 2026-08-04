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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL && n == 1)return NULL;
        int length = 0;

        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            length++; 
        }

        if(length == n){
            return head->next;
        }

        temp = head;
        int count = 1;

        while(temp != NULL){
            if(count == length-n){
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
            count++;
        }
        return head;
    }
};
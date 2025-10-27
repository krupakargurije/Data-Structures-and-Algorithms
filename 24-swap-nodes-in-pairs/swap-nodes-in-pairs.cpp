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

        ListNode* temp = new ListNode(0);//create a dummy node
        temp->next = head; // add next node adress ad head for future 

        ListNode* prev = temp;

        while(head && head->next){
            //create a first and second nodes to swap
            ListNode* first = head;
            ListNode* second = head->next;

            //swap the nodes
            first->next = second->next;
            second->next = first;
            prev->next = second; // to connect the prev node to the swapped node

            //move the prev node to the swaped second node 
            prev = first;
            head = first->next; // move the head to next first node to swap....
        }
        return temp->next;
    }
};
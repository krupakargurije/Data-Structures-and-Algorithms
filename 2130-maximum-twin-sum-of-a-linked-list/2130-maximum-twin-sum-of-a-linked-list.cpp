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
    int pairSum(ListNode* head) {
        int n = 1;

        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
        }

        int k = n / 2;
        ListNode* left = NULL;
        ListNode* right = head;
        temp = right->next;

        while(k--){
            right->next = left;
            left = right;
            right = temp;
            temp = temp->next;
        }
        
        int ans = 0;
        while(left && right){
            ans = max(ans , left->val + right->val);
            left = left->next;
            right = right->next;
        }
        return ans;
    }
};
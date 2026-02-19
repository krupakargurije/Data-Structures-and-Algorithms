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
    int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* node = head;

        while(node->next){
            int a = node->val;
            int b = node->next->val;
            int num = gcd(a,b);
            ListNode* newNode = new ListNode(num);
            newNode->next = node->next;
            node->next = newNode;
            node = newNode->next;
        }
        return head;
    }
};
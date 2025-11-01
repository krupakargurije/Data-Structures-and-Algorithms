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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        if(n == 0 || head == NULL)return head;

        unordered_set<int> st(nums.begin(), nums.end());

        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* prev = temp;

        while(head){
            if(st.find(head->val) != st.end()){
                prev->next = head->next;
                head = head->next;
            }else{
                prev = head;
                head = head->next;
            }
        }
        return temp->next;
    }
};
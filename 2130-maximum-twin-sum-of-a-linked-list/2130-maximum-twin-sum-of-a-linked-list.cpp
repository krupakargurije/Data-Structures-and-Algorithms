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
        temp = head;
        stack<int>st;

        while(k--){
            st.push(temp->val);
            temp = temp->next;
        }

        k = n/2;
        int ans = INT_MIN;

        while(k--){
            int a = st.top();
            st.pop();
            
            ans = max(ans , a + temp->val);
            temp = temp->next;
        }
        return ans;
    }
};
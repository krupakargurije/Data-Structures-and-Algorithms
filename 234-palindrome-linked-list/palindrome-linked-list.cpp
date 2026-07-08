class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Skip the middle node for odd-length lists
        if (fast)
            slow = slow->next;

        // Reverse the second half
        ListNode* second = reverse(slow);

        // Compare the two halves
        ListNode* first = head;
        ListNode* temp = second;

        while (temp) {
            if (first->val != temp->val)
                return false;

            first = first->next;
            temp = temp->next;
        }

        return true;
    }
};
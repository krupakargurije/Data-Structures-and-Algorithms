class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        // Find length
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        int half = n / 2;

        // Reverse first half
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (half--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Skip middle node if length is odd
        if (n % 2 == 1)
            curr = curr->next;

        // Compare
        while (prev && curr) {
            if (prev->val != curr->val)
                return false;

            prev = prev->next;
            curr = curr->next;
        }

        return true;
    }
};
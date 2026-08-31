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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        ListNode* point = head->next;

        int prevNodeVal = head->val;
        int i = 1;

        int first = -1;
        int prev = -1;

        int minDis = INT_MAX;

        while (point->next) {
            int currNodeVal = point->val;

            bool isCritical =
                (currNodeVal < prevNodeVal && currNodeVal < point->next->val) ||
                (currNodeVal > prevNodeVal && currNodeVal > point->next->val);

            if (isCritical) {
                // First critical point
                if (first == -1) {
                    first = i;
                }

                // We already have a previous critical point
                if (prev != -1) {
                    minDis = min(minDis, i - prev);
                }
                prev = i;
            }

            prevNodeVal = currNodeVal;
            point = point->next;
            i++;
        }

        // Fewer than 2 critical points
        if (first == prev)
            return {-1, -1};

        int maxDis = prev - first;

        return {minDis, maxDis};
    }
};
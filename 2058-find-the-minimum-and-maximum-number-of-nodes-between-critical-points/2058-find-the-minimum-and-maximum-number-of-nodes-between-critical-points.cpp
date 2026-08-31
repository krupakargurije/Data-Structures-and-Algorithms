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
        if(!head->next)
            return {-1 , -1};

        ListNode* point = head->next;
        int prevNodeVal = head->val;

        // idx or nodeNumber
        vector<int>criticalPoints;
        int i = 1;

        while(point->next){
            int currNodeVal = point->val;

            if(currNodeVal < prevNodeVal && currNodeVal < point->next->val)
                criticalPoints.push_back(i);
            else if(currNodeVal > prevNodeVal && currNodeVal > point->next->val)
                criticalPoints.push_back(i);
            
            prevNodeVal = currNodeVal;
            point = point->next;
            i++;
        }
        
        if(criticalPoints.size() < 2)
            return {-1 , -1};
        
        int minDis = INT_MAX;

        for(int idx = 1;idx < criticalPoints.size();idx++){
            minDis = min(minDis , criticalPoints[idx] - criticalPoints[idx - 1]);
        }
       int maxDis = criticalPoints.back() - criticalPoints.front();

        return {minDis , maxDis};
    }
};
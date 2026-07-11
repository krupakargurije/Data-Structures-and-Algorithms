/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
            
        Node *temp = head;

        // create copy new nodes
        // insert them in the middle of org nodes
        while(temp){
            Node *newNode = new Node(temp->val);

            newNode->next = temp->next;
            temp->next = newNode;

            temp = newNode->next;
        }

        // fill the random adresses in new nodes
        temp = head;
        while(temp){
            temp->next->random = temp->random ? temp->random->next : NULL;
            temp = temp->next->next;
        }

        // connect new linked list
        // Step 3: Separate the two lists
        temp = head;
        Node* newHead = head->next;

        while (temp) {
            Node* copy = temp->next;
            temp->next = copy->next;

            if (copy->next)
                copy->next = copy->next->next;

            temp = temp->next;
        }
        return newHead;
    }
};
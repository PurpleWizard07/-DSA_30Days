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
        if (!head) return nullptr;

        // Step 1: Interleave copied nodes
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Assign random pointers
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Separate original and copied list
        Node* dummyHead = new Node(0);
        Node* copyCurr = dummyHead;
        curr = head;

        while (curr) {
            Node* copy = curr->next;
            copyCurr->next = copy;
            copyCurr = copy;

            curr->next = copy->next; // restore original list
            curr = curr->next;
        }

        return dummyHead->next;
    }
};

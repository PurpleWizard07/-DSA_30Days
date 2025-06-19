/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* a = headA;
        ListNode* b = headB;

        // Step 1: Calculate lengths
        while (a) {
            lenA++;
            a = a->next;
        }
        while (b) {
            lenB++;
            b = b->next;
        }

        // Step 2: Align both lists
        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }
        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }

        // Step 3: Now both heads are at same distance from intersection.
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA; // may be nullptr if no intersection
    }
};

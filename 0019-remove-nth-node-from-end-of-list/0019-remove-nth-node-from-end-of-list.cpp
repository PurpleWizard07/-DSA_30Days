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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;

    // Move fast n steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // If we have to delete the first node
    if (!fast)
        return head->next;

    // Move both until fast reaches last node
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    // Skip the node
    slow->next = slow->next->next;

    return head;
}

};

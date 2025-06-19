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
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftHead = new ListNode(-1);
        ListNode* rightHead = new ListNode(-1);
        ListNode* left = leftHead;
        ListNode* right = rightHead;

        while (head) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            } else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }

        right->next = nullptr;           // important: end the right list
        left->next = rightHead->next;    // connect left and right lists
        return leftHead->next;
    }
};

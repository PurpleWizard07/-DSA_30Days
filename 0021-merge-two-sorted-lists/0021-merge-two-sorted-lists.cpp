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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* head = &dummy;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            }
            else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        head->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }
};



// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL || list2 == NULL) {
//             return list1 == NULL ? list2 : list1;
//         }

//         if(list1->val <= list2->val) {
//             list1->next = mergeTwoLists(list1->next, list2);
//             return list1;
//         } 
//         else {
//             list2->next = mergeTwoLists(list1, list2->next);
//             return list2;
//         }
//     }
// };
/*
    Find the nth to last element of a singly linked list. 

    The minimum number of nodes in list is n.

    Example
        Given a List  3->2->1->5->null and n = 2, return 
        node whose value is 1.
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    ListNode *nthToLast(ListNode *head, int n) {
        if (!head) return head;
        int cnt = 0;
        for (ListNode *cur = head; cur; cur = cur->next) cnt++;
        n %= cnt + 1;
        ListNode *cur = head;
        for (int i = 0; i < cnt - n; ++i) cur = cur->next;
        return cur;
    }
};

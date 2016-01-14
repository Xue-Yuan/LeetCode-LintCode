/*
    Given a singly linked list L: L0→L1→…→Ln-1→Ln,
        reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

    You must do this in-place without altering the nodes' values.

    For example,
        Given 1->2->3->4->null, reorder it to 1->4->2->3->null.
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
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head->next->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) slow = slow->next;
        //reverse
        ListNode *pre = slow, *ps = slow->next;
        while (ps->next)
        {
            ListNode *p = ps->next;
            ps->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }
        //reorder
        ListNode *cur1 = head, *cur2 = pre->next;
        pre->next = nullptr;
        while (cur2)
        {
            ListNode *tmp = cur2->next;
            cur2->next = cur1->next;
            cur1->next = cur2;
            cur2 = tmp;
            cur1 = cur1->next->next;
        }
    }
};

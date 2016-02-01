/*
    Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

    Example
        Given 1->2->3->3->4->4->5, return 1->2->5.
        Given 1->1->1->2->3, return 2->3.
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

 //Do it on the fly.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode ph(0), *pre = &ph;
        pre->next = head;
        while (pre->next)
        {
            ListNode *cur = pre->next;
            if (cur->next && cur->val == cur->next->val)
            {
                while (cur->next && cur->val == cur->next->val)
                {
                    ListNode *tmp = cur->next->next;
                    delete cur->next;
                    cur->next = tmp;
                }
                pre->next = cur->next;
                delete cur;
            }
            else pre = cur;
        }
        return ph.next;
    }
};

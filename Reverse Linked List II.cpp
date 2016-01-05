/*
    Reverse a linked list from position m to n. Do it in-place and in 
        one-pass.

    For example:
        Given 1->2->3->4->5->NULL, m = 2 and n = 4,

        return 1->4->3->2->5->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode ph(0), *pre = &ph, *ps;
        pre->next = head;
        for (int i = 0; i < m - 1; ++i) pre = pre->next;
        ps = pre->next;
        for (int i = m; i < n; ++i)
        {
            ListNode *p = ps->next;
            ps->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }
        return ph.next;
    }
};

/*
    Given a linked list, reverse the nodes of a linked list k at a 
        time and return its modified list.

    If the number of nodes is not a multiple of k then left-out nodes 
        in the end should remain as it is.

    You may not alter the values in the nodes, only nodes itself may 
        be changed.

    Only constant memory is allowed.

    For example,
        Given this linked list: 1->2->3->4->5

        For k = 2, you should return: 2->1->4->3->5

        For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head || !head->next || k == 1) return head;
        //in case the nodes left over are less than k.
        ListNode *cur = head;
        for (int i = 0; i < k; ++i, cur = cur->next)
            if (!cur) return head;

        ListNode ph(0);
        ph.next = head;
        ListNode *pre = &ph, *ps = pre->next;
        for(int i = 0; i < k-1; ++i)
        {
            ListNode *p = ps->next;
            ps->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }
        ps->next = reverseKGroup(ps->next, k);
        return ph.next;
    }  
};

/*
    Given a linked list, remove the nth node from the end of list and return its head.

    For example,

       Given linked list: 1->2->3->4->5, and n = 2.

       After removing the second node from the end, the linked list becomes 1->2->3->5.
    Note:
    Given n will always be valid.
    Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <vector>

using std::vector;

class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(!head) return head;
        ListNode *t = head;
        int cnt = 0;
        while(t)
        {
            ++cnt;
            t = t->next;
        }
        
        ListNode ph(0);
        ph.next = head;
        t = &ph;
        for(int i = 0; i < cnt - n; ++i)
        {
            t = t->next;
        }
        ListNode *cur = t->next;
        if(cur)
        {
            t->next = cur->next;
            delete cur;
        }
        return ph.next;
    }
};
/*
    Given a linked list and a value x, partition it such that all nodes 
        less than x come before nodes greater than or equal to x.

    You should preserve the original relative order of the nodes in each 
        of the two partitions.

    For example,
        Given 1->4->3->2->5->2 and x = 3,
        return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode ph1(0), *pre1 = &ph1, ph2(0), *pre2 = &ph2;
        while (head)
        {
            ListNode *&min = head->val < x ? pre1 : pre2;
            min->next = head;
            min = min->next;
            head = head->next;
        }
        pre1->next = ph2.next;
        pre2->next = nullptr;
        return ph1.next;
    }
};

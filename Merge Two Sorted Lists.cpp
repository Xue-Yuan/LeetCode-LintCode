/*
    Merge two sorted linked lists and return it as a new 
        list. The new list should  be made by splicing 
        together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode ph(0), *cur = &ph;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        while(l1)
        {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2)
        {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
        return ph.next;
    }
    //recursively
    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) 
    {
        if(l1 == nullptr)
        {
            return l2;
        }
        if(l2 == nullptr)
        {
            return l1;
        }
        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


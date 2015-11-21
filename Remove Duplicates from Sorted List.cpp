/*
    Given a sorted linked list, delete all duplicates 
        such that each element appear only once.

    For example,
    Given 1->1->2, return 1->2.
    Given 1->1->2->3->3, return 1->2->3.

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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head || !head->next) return head;
        ListNode *pre = head, *cur = head->next;
        
        while(cur)
        {
            while(cur && pre->val == cur->val)
            {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            pre = cur;
            if(cur) cur = cur->next;
        }
        return head;
    }
};
/*
    You are given two linked lists representing two non-negative 
        numbers. The digits are stored in reverse order and each 
        of their nodes contain a single digit. Add the two numbers 
        and return it as a linked list.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    
    Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode ph(0), *pre = &ph;
        int sum = 0, carry = 0;
        
        while (l1 || l2 || carry)
        {
            sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum > 9;
            pre->next = new ListNode(sum % 10);
            pre = pre->next;
        }
        return ph.next;
    }
};
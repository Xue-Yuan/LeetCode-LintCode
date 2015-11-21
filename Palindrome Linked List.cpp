/*
    Given a singly linked list, determine if it is a palindrome.

    Follow up:
    Could you do it in O(n) time and O(1) space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
    Have to change the structure at least temporarily. One can reverse
        it back later if not comfortable with this.

    The slow and fast pointer to find the middle. Regardless of the odd
        or even number of nodes, the slow pointer will always stop one 
        node before the latter half of the list.
 */
class Solution 
{
private:
    ListNode *reverse(ListNode *head)
    {
        ListNode ph(0), *pre = &ph, *ps = head;
        ph.next = head;
        while(ps->next)
        {
            ListNode *p = ps->next;
            ps->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }
        return ph.next;
    }
public:
    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        while(slow)
        {
            if(head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};
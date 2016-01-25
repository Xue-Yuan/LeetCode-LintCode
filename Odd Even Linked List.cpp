/*
    Given a singly linked list, group all odd nodes together followed 
        by the even nodes. Please note here we are talking about the 
        node number and not the value in the nodes.

    You should try to do it in place. The program should run in O(1) 
        space complexity and O(nodes) time complexity.

    Example:
        Given 1->2->3->4->5->NULL,
        return 1->3->5->2->4->NULL.

    Note:
    The relative order inside both the even and odd groups should remain 
        as it was in the input. 
    The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode odd(0), even(0), *pre1 = &odd, *pre2 = &even;
        while (head)
        {
            pre1->next = head;
            pre1 = pre1->next;
            head = head->next;
            if (head) 
            {
                pre2->next = head;
                pre2 = pre2->next;
                head = head->next;
            }
        }
        pre1->next = even.next;
        pre2->next = nullptr;
        return odd.next;
    }
};

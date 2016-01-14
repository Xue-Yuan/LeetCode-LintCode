/*
    Sort a linked list in O(n log n) time using constant space complexity.
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

class Solution 
{
private:
    ListNode *sortList(ListNode *head, ListNode *tail)
    {
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (fast != tail && fast->next != tail)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *cur1 = sortList(head, slow);
        ListNode *cur2 = sortList(slow, tail);
        //merge
        ListNode ph(0), *pre = &ph;
        while (cur1 && cur2 )
        {
            ListNode *&min = cur1->val < cur2->val ? cur1 : cur2;
            pre->next = min;
            pre = pre->next;
            min = min->next;
        }
        if (cur1) pre->next = cur1;
        if (cur2) pre->next = cur2;
        return ph.next;
    }
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) 
    {
        // write your code here
        if (!head) return nullptr;
        return sortList(head, nullptr);    
    }
};

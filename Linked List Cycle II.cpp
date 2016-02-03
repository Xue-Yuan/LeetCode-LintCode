/*
	Given a linked list, return the node where the cycle begins.

	If there is no cycle, return null.

	Example
		Given -21->10->4->5, tail connects to node index 1，return 10
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
public:
    ListNode *detectCycle(ListNode *head) 
    {
        unordered_set<ListNode *> s;
        while (head)
        {
            if (s.find(head) != s.end()) return head;
            s.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        bool cycle = false;
        while (!cycle && fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            cycle = fast == slow;
        }
        if (!cycle) return nullptr;
        
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

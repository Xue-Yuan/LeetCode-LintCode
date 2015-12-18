/*
    A linked list is given such that each node contains an additional 
        random pointer which could point to any node in the list or 
        null.

    Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution 
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (!head) return nullptr;
        
        RandomListNode ph(0), *pre = &ph, *cur = head;
        unordered_map<RandomListNode *, RandomListNode *> m;
        m[nullptr] = nullptr;
        
        while(cur)
        {
            //next
            if (m.find(cur) == m.end())
            {
                pre->next = new RandomListNode(cur->label);
                m[cur] = pre->next;
            }
            else
                pre->next = m[cur];
            //random
            if (m.find(cur->random) == m.end())
            {
                pre->next->random = new RandomListNode(cur->random->label);
                m[cur->random] = pre->next->random;
            }
            else
                pre->next->random = m[cur->random];
            
            pre = pre->next;
            cur = cur->next;
        }
        return ph.next;
    }
};
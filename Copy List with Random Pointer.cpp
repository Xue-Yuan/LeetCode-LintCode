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
        unordered_map<RandomListNode *, RandomListNode *> m;
        m[nullptr] = nullptr;
        
        RandomListNode ph(0), *pre = &ph;
        while (head)
        {
            if (m.find(head) == m.end())
                m[head] = new RandomListNode(head->label);
            if (m.find(head->random) == m.end())
                m[head->random] = new RandomListNode(head->random->label);
            pre->next = m[head];
            pre->next->random = m[head->random];
            head = head->next;
            pre = pre->next;
        }
        return ph.next;
    }
};

//splice the new one with the original.
class Solution2
{
    RandomListNode *copyRandomList_1(RandomListNode *head) 
    {
        if (!head) return nullptr;
        
        for (RandomListNode *cur = head; cur; cur = cur->next->next)
        {
            RandomListNode *tmp = new RandomListNode(cur->label);
            tmp->next = cur->next;
            cur->next = tmp;
        }
        
        for (RandomListNode *cur = head; cur; cur = cur->next->next)
            if (cur->random) cur->next->random = cur->random->next;
            
        RandomListNode ph(0), *pre = &ph;
        for (RandomListNode *cur = head; cur; cur = cur->next)
        {
            pre->next = cur->next;
            pre = pre->next;
            cur->next = pre->next;
        }
        
        return ph.next;
    }
};

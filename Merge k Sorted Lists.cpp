/*
    Merge k sorted linked lists and return it as one sorted 
        list. Analyze and describe its complexity.
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
    Average length n;
    k/2*(2n) + k/4*(4n) + ... +  = logk * (kn)
 */
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.empty()) return nullptr;
        if(lists.size() == 1) return lists[0];
        while(lists.size() > 1)
        {
            vector<ListNode *> tmp;
            for(int i = 0; i < lists.size(); i += 2)
            {
                if(i == lists.size() - 1)
                {
                    tmp.push_back(lists[i]);
                    break;
                }
                tmp.push_back(merge2Lists(lists[i] , lists[i + 1]));
            }
            lists = move(tmp);
        }
        return lists[0];
    }
    ListNode *merge2Lists(ListNode *l1, ListNode *l2) 
    {
        ListNode ph(0), *cur = &ph;
        while (l1 && l2) 
        {
            ListNode *&min = l1->val < l2->val ? l1 : l2;
            cur->next = min;
            cur = cur->next;
            min = min->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return ph.next;
    }
};
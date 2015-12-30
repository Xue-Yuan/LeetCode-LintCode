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

//Use priority_queue, of the same time complexity.
class Solution2
{
private:
    struct myGreater
    {
        bool operator()(ListNode *&a, ListNode *&b) {return a->val > b->val;}
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, myGreater> pq;
        for (auto &e : lists)
            if (e) pq.push(e);  //Pay attention here! We have to check first
        
        ListNode ph(0), *pre = &ph;
        while (!pq.empty())
        {
            pre = pre->next = pq.top();
            pq.pop();
            if (pre->next) pq.push(pre->next);
        }
        return ph.next;
    }
};
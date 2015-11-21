#include <iostream>
// #include "algorithm.h"
// #include "algorithm.cpp"
#include <map>
#include <string>
#include <vector>
#include <random>
#include <sstream>
#include <stack>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <fstream>

using namespace std;

struct listNode
{
    int val;
    listNode *next;
    listNode(int x):val(x), next(nullptr){}
};

listNode *reverse(listNode *p, listNode *c, listNode *n)
{
    c->next = p;
    if(!n) return c;
    return reverse(c, n, n->next);
}

listNode *reverse(listNode *head)
{
    if(!head) return nullptr;
    if(!head->next) return head;
    auto ret = reverse(head, head->next, head->next->next);
    head->next = nullptr;
    return ret;    
}

/************  with a tail *******************/
listNode *reverse(listNode *p, listNode *c, listNode *n, listNode *tail)
{
    c->next = p;
    if(n == tail) return c;
    return reverse(c, n, n->next, tail);
}

//not inclusive
listNode *reverse(listNode *head, listNode *tail)
{
    if(!head || !head->next) return head;
    auto ret = reverse(head, head->next, head->next->next, tail);
    head->next = tail;
    return ret;
}
/*********************************************/

//Non-recursive solution
class Solution 
{
public:
    listNode* reverseList(listNode* head) 
    {
        if(!head || !head->next) return head;
        listNode *p = head, *c = p->next, *n = c->next;
        p->next = nullptr;
        
        while(c)
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
    listNode *reverseList2(listNode* head)
    {
        if(!head || !head->next) return head;
        listNode prehead(0);
        prehead.next = head;
        listNode *pre = &prehead;
        listNode *pstart = prehead.next;
        while(pstart->next)
        {
            listNode *p = pstart->next;
            pstart->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }
        return prehead.next;
    }
};

int main()
{
    // Solution so;
    listNode *A[10];
    for(int i = 0; i < 10; ++i)
        A[i] = new listNode(i);
    for(int i = 0; i < 9; ++i)
        A[i]->next = A[i+1];
    Solution so;
    auto t = so.reverseList2(A[0]);
    for(;t; t = t->next)
        cout << t->val;
    cout << endl;

    return 0;
}

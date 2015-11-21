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

listNode *reverse(listNode *head, int k)
{
    if(!head) return nullptr;
    stack<listNode *> stk;
    listNode *t = head, *cur = new listNode(0), *beforehead = new listNode(0);
    beforehead = cur;
    int cnt = 0;
    while(t)
    {
        while(cnt < k && t)
        {
            stk.push(t);
            t = t->next;
            cnt++;
        }
        while(!stk.empty())
        {
            cur->next = stk.top();
            cur = stk.top();
            stk.pop();
        }
        cnt = 0;
    }
    cur->next = nullptr;
    return beforehead->next;
}


listNode *reverse2(listNode *head, int k)
{
    if(!head) return nullptr;
    if(!head->next) return head;
    listNode *p = head, *c = head->next, *n = c->next;
    int cnt = 0;
    while(cnt < k-1 && c)
    {
        c->next = p;
        p = c;
        c = n;
        if(n) n = n->next;
        cnt++;
    }
    head->next = reverse2(c, k);
    return p;
}

listNode *reverse3(listNode *head, int k)
{
    if(!head) return nullptr;
    if(!head->next) return head;
    listNode prehead(0);
    prehead.next = head;
    listNode *pre = &prehead, *pstart = pre->next;
    for(int i = 0; i < k-1; ++i)
    {
        listNode *p = pstart->next;
        pstart->next = p->next;
        p->next = pre->next;
        pre->next = p;
    }
    pstart->next = reverse3(pstart->next, k);
    return prehead.next;
}

int main()
{
    // Solution so;
    listNode *A[10];
    for(int i = 0; i < 10; ++i)
        A[i] = new listNode(i);
    for(int i = 0; i < 9; ++i)
        A[i]->next = A[i+1];
    auto t = reverse3(A[0], 2);
    for(;t; t = t->next)
        cout << t->val;
    cout << endl;

    return 0;
}

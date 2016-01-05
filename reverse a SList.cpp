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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
};

class Solution
{
private:
    ListNode* reverseList(ListNode *reversed, ListNode *remaining)
    {
        if (!remaining) return reversed;
        ListNode *tmp = remaining->next;
        remaining->next = reversed;
        return reverseList(remaining, tmp);
    }
public:
    ListNode* reverseList(ListNode *head)
    {
        return reverseList(nullptr, head);
    }
};

class Solution1
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next) return head;
        ListNode *ret = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ret;
    } 
};

//Non-recursive solution
class Solution2 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next) return head;
        ListNode *p = head, *c = p->next, *n = c->next;
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
};

class Solution3
{
public:
    ListNode *reverseList(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode prehead(0);
        prehead.next = head;
        ListNode *pre = &prehead;
        ListNode *pstart = prehead.next;
        while(pstart->next)
        {
            ListNode *p = pstart->next;
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
    ListNode *A[10];
    for(int i = 0; i < 10; ++i)
        A[i] = new ListNode(i);
    for(int i = 0; i < 9; ++i)
        A[i]->next = A[i+1];
    Solution so;
    auto t = so.reverseList2(A[0]);
    for(;t; t = t->next)
        cout << t->val;
    cout << endl;

    return 0;
}

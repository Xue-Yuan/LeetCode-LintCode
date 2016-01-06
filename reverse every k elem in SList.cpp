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

//If the number of nodes is not a multiple of k then left-out nodes 
//  in the end are still reversed.
ListNode *reverse(ListNode *head, int k)
{
    if(!head) return nullptr;
    stack<ListNode *> stk;
    ListNode *t = head, *cur = new ListNode(0), *beforehead = new ListNode(0);
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

int main()
{
    // Solution so;
    ListNode *A[10];
    for(int i = 0; i < 10; ++i)
        A[i] = new ListNode(i);
    for(int i = 0; i < 9; ++i)
        A[i]->next = A[i+1];
    auto t = reverse3(A[0], 2);
    for(;t; t = t->next)
        cout << t->val;
    cout << endl;

    return 0;
}

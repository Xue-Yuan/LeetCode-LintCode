/*
    Two queue stack. Two version:
        1. efficient in pushing
        2. efficient in poping
*/
#include <queue>

/*
    This version is efficient in pushing
*/
using namespace std;

class myStack
{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int x)
    {
        q1.push(x);
    }
    int pop()
    {
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int cache = q1.front();
        q1.pop();
        swap(q1, q2);
        return cache;
    }
    int top()
    {
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int cache = q1.front();
        q2.push(cache);
        q1.pop();
        swap(q1, q2);
        return cache;    
    }
    bool empty()
    {
        return q1.empty();
    }
};
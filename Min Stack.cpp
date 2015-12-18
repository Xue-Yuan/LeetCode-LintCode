/*
    Design a stack that supports push, pop, top, and retrieving the 
        minimum element in constant time.

    push(x) -- Push element x onto stack.

    pop() -- Removes the element on top of the stack.

    top() -- Get the top element.

    getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack 
{
private:
    stack<int> elems;
    stack<int> mins;
public:
    void push(int x) 
    {
        elems.push(x);
        if (mins.empty() || x <= mins.top())
            mins.push(x);
    }

    void pop() 
    {
        if (elems.empty()) return;
        if (mins.top() == elems.top()) mins.pop();
        elems.pop();
    }

    int top() 
    {
        return elems.top();
    }

    int getMin()
    {
        return mins.top();
    }
};

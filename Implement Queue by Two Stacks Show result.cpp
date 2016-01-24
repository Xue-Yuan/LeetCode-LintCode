/*
    As the title described, you should only use two stacks to 
        implement a queue's actions.

    The queue should support push(element), pop() and top() 
        where pop is pop the first(a.k.a front) element in the queue.

    Both pop and top methods should return the value of first element.

    Example
    push(1)
    pop()     // return 1
    push(2)
    push(3)
    top()     // return 2
    pop()     // return 2
*/
class Queue {
public:
    stack<int> stack1;  //top, pop
    stack<int> stack2;  //push

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack2.push(element);
    }
    
    int pop() {
        // write your code here
        if (stack1.empty())
        {
            while (!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        int ret = stack1.top();
        stack1.pop();
        return ret;
    }

    int top() {
        // write your code here
        if (stack1.empty())
        {
            while (!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        return stack1.top();
    }
};

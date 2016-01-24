/*
    Implement a stack with min() function, which will return 
        the smallest number in the stack.

    It should support push, pop and min operation all in O(1) cost.

    Have you met this question in a real interview? Yes
    Example
    push(1)
    pop()   // return 1
    push(2)
    push(3)
    min()   // return 2
    push(1)
    min()   // return 1
*/

class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        elem.push_back(number);
        if (minV.empty()) minV.push_back(number);
        //have to call min by std::min
        else minV.push_back(std::min(minV.back(), number));
    }

    int pop() {
        // write your code here
        int ret = elem.back();
        elem.pop_back();
        minV.pop_back();
        return ret;
    }

    int min() {
        // write your code here
        return minV.back();
    }
private:
    vector<int> elem;
    vector<int> minV;
};

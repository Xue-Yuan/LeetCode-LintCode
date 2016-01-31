/*
    Implement a basic calculator to evaluate a simple expression string.

    The expression string may contain open ( and closing parentheses ), 
        the plus + or minus sign -, non-negative integers and empty 
        spaces .

    You may assume that the given expression is always valid.

    Some examples:
        "1 + 1" = 2
        " 2-1 + 2 " = 3
        "(1+(4+5+2)-3)+(6+8)" = 23
*/
class Solution 
{
private:
    //op2 has higher priority or the same priority as op1
    bool isPrior(char op1, char op2)
    {
        if(op2 == '(' || op2 == ')') return false;
        return !((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'));
    }
    /*
        get an operator from ops, 2 operands from vals
    */
    void eval(stack<int> &vals, stack<char> &ops)
    {
        if(ops.empty() || vals.empty()) return;
        char op = ops.top(); ops.pop();
        int A = vals.top(); vals.pop();
        int B = vals.top(); vals.pop();
        if(op == '+') vals.push(A + B);
        else if(op == '-') vals.push(B - A);
        else if(op == '*') vals.push(A * B);
        else if(op == '/') vals.push(B / A);
    }
public:
    int calculate(string s) 
    {
        stack<int> vals;
        stack<char> ops;
        string buf = "";
        istringstream input(s);
        char c;
        while(input >> c)
        {
            // cout << c << endl;
            if(c >= '0' && c <= '9')
            {
                while(c >= '0' && c <= '9')
                {
                    buf += c;
                    if(!(input >> c)) break;
                }
                vals.push(stoi(buf));
                buf.clear();
            }
            if(c == '(')
                ops.push(c);
            else if(c == ')')
            {
                while(!ops.empty() && ops.top() != '(')
                {
                    eval(vals, ops);
                }
                if(ops.top() == '(') ops.pop();
                else
                {
                    cout << "Parentheses mismatch!" << endl;
                    return -1;
                }
            }
            else if(c == '+' || c =='-' || c =='/' || c == '*')
            {
                while(!ops.empty() && isPrior(c, ops.top()))
                {
                    eval(vals, ops);
                }
                ops.push(c);
            }
        }
        while(!ops.empty())
            eval(vals, ops);        
        return vals.top();
    }
};
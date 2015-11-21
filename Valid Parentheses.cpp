/*
    Given a string containing just the characters 
        '(', ')', '{', '}', '[' and ']', determine 
        if the input string is valid.

    The brackets must close in the correct order, 
        "()" and "()[]{}" are all valid but "(]" 
        and "([)]" are not.
*/

#include <vector>

using std::vector

class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> stk;
        for(auto &c : s)
        {
            switch(c)
            {
                case '(':
                case '[':
                case '{':
                    stk.push(c);
                    break;
                case ')':
                {
                    if(stk.empty() || stk.top() != '(') return false;
                    stk.pop();
                    break;
                }
                case ']':
                {
                    if(stk.empty() || stk.top() != '[') return false;
                    stk.pop();
                    break;
                }
                case '}':
                {
                    if(stk.empty() || stk.top() != '{') return false;
                    stk.pop();
                    break;
                }
            }
        }
        return stk.empty();
    }
};
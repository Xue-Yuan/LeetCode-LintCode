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

class Solution2 
{
public:
    bool isValid(string s) 
    {
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else
            {
                if (stk.empty() || abs(stk.top() - s[i]) > 2) 
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
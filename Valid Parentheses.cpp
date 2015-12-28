/*
    Given a string containing just the characters 
        '(', ')', '{', '}', '[' and ']', determine 
        if the input string is valid.

    The brackets must close in the correct order, 
        "()" and "()[]{}" are all valid but "(]" 
        and "([)]" are not.
*/
class Solution
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
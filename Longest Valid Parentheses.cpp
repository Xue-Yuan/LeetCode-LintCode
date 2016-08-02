/*
    Given a string containing just the characters '(' and ')', 
        find the length of the longest valid (well-formed) 
        parentheses substring.

    For "(()", the longest valid parentheses substring is "()", 
        which has length = 2.

    Another example is ")()())", where the longest valid 
        parentheses substring is "()()", which has length = 4.
*/

/*
 https://leetcode.com/discuss/8092/my-dp-o-n-solution-without-using-stack
*/
class Solution
{
public:
    int longestValidParentheses2(string s)
    {
        if(s.length() <= 1)
            return 0;
        int curMax = 0;
        vector<int> longest(s.size(), 0);
        for(int i=1; i < s.length(); i++)
        {
            if(s[i] == ')' && i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '(')
            {
                longest[i] = longest[i - 1] + 2 + 
                    ((i - longest[i - 1] - 2 >= 0) ? 
                        longest[i - longest[i - 1] - 2] : 0);
                curMax = max(longest[i], curMax);
            }
        }
        return curMax;
    }
    
};
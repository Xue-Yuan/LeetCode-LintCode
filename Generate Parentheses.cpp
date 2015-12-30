/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution 
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        generateParenthesis("", n, n, ret);
        return ret;
    }
    
    void generateParenthesis(string str, int left, int right, vector<string> &ret)
    {
        if (left == 0 && right == 0)
        {
            ret.push_back(str);
            return;
        }
        if (left > 0) generateParenthesis(str + "(", left - 1, right, ret);
        if (right > left) generateParenthesis(str + ")", left, right - 1, ret);
    }
};
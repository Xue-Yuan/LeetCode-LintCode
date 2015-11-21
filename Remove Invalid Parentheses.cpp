/*
    Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

        Note: The input string may contain letters other than the parentheses ( and ).

    Examples:
    "()())()" -> ["()()()", "(())()"]
    "(a)())()" -> ["(a)()()", "(a())()"]
    ")(" -> [""]
*/

#include <vector>

using namespace std;

class Solution {
private:
    bool isValid(string s)
    {
        int sum = 0;
        for(auto &c : s)        //check whether s is valid or not
        {
            if(c == '(') ++sum;
            else if(c == ')') --sum;
            if(sum < 0) return false;
        }
        return sum == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) 
    {
        int num1 = 0, num2 = 0, sum = 0;
        int beg = 0, end = s.size() - 1;
        while(s[beg] == ')') ++beg;
        while(s[end] == '(') --end;
        s = s.substr(beg, end - beg + 1);
        for(auto &c : s)
        {
            if(c == '(') ++sum;
            else if(c == ')') --sum;
            num2 = min(sum, num2);
        }
        num1 = sum - num2;
        vector<string> ret;
        removeInvalidParentheses(s, 0, num1, num2, ret);
        return ret;
    }
    
    void removeInvalidParentheses(string s, int beg, int num1, int num2, vector<string> &ret)
    {
        if(num1 == 0 && num2 == 0)
        {   
            if(isValid(s))
                ret.push_back(s);
            return;
        }
        for(int i = beg; i < s.size(); ++i)
        {
            string tmp = s;
            /*
                The num2 == 0 expression is hard. All invalid '('
                    can only appear after invalid ')', otherwise 
                    there is no invalid ')'. It's OK we don't add
                    this num2 == 0 test, without which only slow
                    down the performance a little bit.
            */
            if(num2 == 0 && num1 > 0 && tmp[i] == '(')
            {
                if(i == beg || tmp[i] != tmp[i - 1])
                {
                    tmp.erase(i, 1);
                    removeInvalidParentheses(tmp, i, num1 - 1, num2, ret);
                }
            }
            if(num2 < 0 && tmp[i] == ')')
            {
                if(i == beg || tmp[i] != tmp[i - 1])
                {
                    tmp.erase(i, 1);
                    removeInvalidParentheses(tmp, i, num1, num2 + 1, ret);
                }
            }

        }
    }
};
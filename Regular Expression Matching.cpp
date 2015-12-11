/*
    Implement regular expression matching with support for '.' and '*'.

    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.

    The matching should cover the entire input string (not partial).

    The function prototype should be:
    bool isMatch(const char *s, const char *p)

    Some examples:
    isMatch("aa","a") → false
    isMatch("aa","aa") → true
    isMatch("aaa","aa") → false
    isMatch("aa", "a*") → true
    isMatch("aa", ".*") → true
    isMatch("ab", ".*") → true
    isMatch("aab", "c*a*b") → true
*/

//http://leetcode.com/2011/09/regular-expression-matching.html

class Solution
{
private:
    bool isMatch(const string &s, int b1, const string &p, int b2)
    {
        if (b2 == p.size())
            return b1 == s.size();
        if (b2 == p.size() - 1 || p[b2 + 1] != '*')
            return b1 != s.size() && (s[b1] == p[b2] || p[b2] == '.') && isMatch(s, b1 + 1, p, b2 + 1);
        //p = x*
        //jump directly
        if (isMatch(s, b1, p, b2 + 2))
            return true;
        //do the match
        if (b1 < s.size() && (s[b1] == p[b2] || p[b2] == '.'))
            return isMatch(s, b1 + 1, p, b2);
        return false;
    }

    bool isMatch_2(const string &s, int b1, const string &p, int b2)
    {
        if (b2 == p.size())
            return b1 == s.size();
        if (b1 < s.size() && (s[b1] == p[b2] || p[b2] == '.'))
        {
            if (p[b2 + 1] == '*')
                return isMatch(s, b1 + 1, p, b2) || isMatch(s, b1, p, b2 + 2);
            else
                return isMatch(s, b1 + 1, p, b2 + 1);
        }
        return p[b2 + 1] == '*' && isMatch(s, b1, p, b2 + 2);
    }

public:
    bool isMatch(string s, string p)
    {
        return isMatch(s, 0, p, 0);
    }
};

class Solution_2
{
public:
    bool isMatch(string s, string p)
    {
        //dp[i][j] match of s.substr(0, i - 1) and p.substr(0, j - 1)
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        
        //How to match empty s?
        //Think about "c*c*", "a*c*"
        for (int i = 2; i < dp[0].size(); ++i)
            dp[0][i] = dp[0][i - 2] && p[i - 1] == '*';
        
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 1; j < dp[0].size(); ++j)
            {
                if (p[j - 1] != '*')
                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
                else
                    dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
            }
        }
        return dp[s.size()][p.size()];
    }
};
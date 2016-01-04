/*
    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty 
        sequence).

    The matching should cover the entire input string (not partial).

    The function prototype should be:
    bool isMatch(const char *s, const char *p)

    Some examples:
    isMatch("aa","a") → false
    isMatch("aa","aa") → true
    isMatch("aaa","aa") → false
    isMatch("aa", "*") → true
    isMatch("aa", "a*") → true
    isMatch("ab", "?*") → true
    isMatch("aab", "c*a*b") → false
*/

// class Solution
// {
// private:
//     bool isMatch(const string &s, int b1, const string &p, int b2)
//     {
//         if (b2 == p.size())
//             return b1 == s.size();
//         if (b1 != s.size() && p[b2] != '*')
//             return (s[b1] == p[b2] || p[b2] == '?') && isMatch(s, b1 + 1, p, b2 + 1);
//         if (b1 != s.size())
//             return isMatch(s, b1 + 1, p, b2 + 1) || isMatch(s, b1 + 1, p, b2);
//         return false;
//     }
// public:
//     bool isMatch(string s, string p)
//     {
//         return isMatch(s, 0, p, 0);
//     }
// };

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if(p.empty())
            return s.empty();
        
        vector<vector<bool>> matched(2, vector<bool>(s.size() + 1, false));
        matched[0][0] = true;
        
        int cur = 1, prev = 0;
        for(int i = 1; i <= p.size(); ++i)
        {
            matched[cur][0] = matched[prev][0] && p[i - 1]== '*';
            
            for(int j = 1; j <= s.size(); ++j)
            {
                if(p[i - 1] == '*')
                    matched[cur][j] = matched[cur][j - 1] || matched[prev][j];
                else
                    matched[cur][j] =  matched[prev][j - 1] && (p[i - 1] == '?' || p[i - 1] == s[j - 1]);
            }
            swap(cur, prev);
        }
        return matched[prev][s.size()];
    }
};

//Taken from https://leetcode.com/discuss/43966/accepted-c-dp-solution-with-a-trick
class Solution2
{
public:
    bool isMatch(string s, string p) 
    {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterisk = -1, match;
        while (i < m) 
        {
            if (j < n && p[j] == '*') 
            {
                match = i; 
                asterisk = j++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?'))
            {
                i++; 
                j++;
            }
            else if (asterisk >= 0) 
            {
                i = ++match;
                j = asterisk + 1;
            }
            else return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};

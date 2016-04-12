/*
    Given a roman numeral, convert it to an integer.

    Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution 
{
private:
    int lookup(char C)
    {
        switch (C)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
        return 0;
    }
public:
    int romanToInt(string s) 
    {
        int res = 0;
        for (int i = 0; i < (int)s.size() - 1; ++i)
        {
            if (lookup(s[i]) < lookup(s[i + 1])) res -= lookup(s[i]);
            else res += lookup(s[i]);
        }
        return res += lookup(s.back());
    }
};

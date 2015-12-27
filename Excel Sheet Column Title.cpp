/*
    Given a positive integer, return its corresponding column 
        title as appear in an Excel sheet.

    For example:

        1 -> A
        2 -> B
        3 -> C
        ...
        26 -> Z
        27 -> AA
        28 -> AB 
*/

class Solution
{
public:
    string convertToTitle(int n)
    {
        string ret = "";
        while (n > 0)
        {
            ret.push_back(char((n - 1) % 26 + 'A'));
            n = (n - 1) / 26;
        }
        return {ret.rbegin(), ret.rend()};
    }
};
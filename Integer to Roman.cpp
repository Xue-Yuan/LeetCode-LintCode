/*
    Given an integer, convert it to a roman numeral.

    Input is guaranteed to be within the range from 1 to 3999.
*/

/*
    M 1000         CM 900
    D 500          CD 400
    C 100          XC 90
    L 50           XL 40
    X 10            
    V 5
    I 1
*/
class Solution
{
public:
    string intToRoman(int num)
    {
        static vector<vector<string>> table =
        {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"},
        };
        
        string res{""};
        for (int i = 3; i >= 0; i--)
        {
            int divisor = (int)pow(10, i);
            res += table[i][num / divisor];
            num %= divisor;
        }
        return res;
    }
};

/*
    The string "PAYPALISHIRING" is written in a zigzag pattern 
        on a given number of rows like this: (you may want to 
        display this pattern in a fixed font for better legibility)
    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
    Write the code that will take a string and make this conversion 
        given a number of rows:
    string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

/*
    Based on the observation:

    0     6     12
     1   5 7   11 13
      2 4   8 10   14
       3     9
       
    The first line and the last line need to be treated specially.
*/
class Solution
{
public:
    string convert(string s, int numRows) 
    {
        if (numRows < 2 || s.size() < 2) return s;
        string str;
        int step = 2 * (numRows - 1);
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < s.size() + step; j += step)
            {
                if (j - i >= 0 && j - i < s.size())
                    str += s[j - i];
                if (i == 0 || i == numRows - 1) continue;    //avoid double counting in the boundary.
                if (j + i < s.size())
                    str += s[j + i];
            }
        }
        return str;
    }
};

//straightforward
class Solution2
{
public:
    string convert(string s, int numRows) 
    {
        vector<string> zigzag(numRows);
        for (int i = 0; i < s.size();)
        {
            for (int j = 0; j < numRows && i < s.size(); ++j, ++i)
                zigzag[j] += s[i];
            for (int j = numRows - 2; j >= 1 && i < s.size(); --j, ++i)
                zigzag[j] += s[i];
        }
        string res{""};
        for (auto &s : zigzag) res += s;
        return res;
    }
};

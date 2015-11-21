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
        if(numRows == 0) return "";
        if(numRows == 1) return s;
        
        int base0 = numRows - 1, base1 = numRows - 1, base2 = 2*numRows - 2;
        string res = "";
        for(int i = 0; i < numRows; ++i)
        {
            base1 = numRows - 1;
            int n = i;
            while(n < s.size())
            {
                res += s[n];
                if(i % (2 * (numRows - 1)) == 0)
                {
                    n = base0 * 2 - n;
                    base0 += 2 * (numRows - 1);
                }
                else if(i % (numRows - 1) == 0)
                {
                    n = base2 * 2 - n;
                    base2 += 2 * (numRows - 1);
                }
                else
                {
                    n = base1 * 2 - n;
                    base1 += (numRows - 1);
                }
            }   
        }
        return res;
    }
};
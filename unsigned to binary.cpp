//For positive number
class Solution 
{
public:
    string intToBinary(unsigned m) 
    {
        if (m == 0) return "0";
        string res;
        while (m > 0)
        {
            res += '0' + (m & 0x1);
            m >>= 1;
        }
        return {res.rbegin(), res.rend()};
    }
};

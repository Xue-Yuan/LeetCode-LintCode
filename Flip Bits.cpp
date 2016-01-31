/*
    Determine the number of bits required to flip if you want to convert 
        integer n to integer m.

    Example
        Given n = 31 (11111), m = 14 (01110), return 2.

    Note
        Both n and m are 32-bit integers.
*/

class Solution 
{
public:
    int bitSwapRequired(int a, int b) 
    {
        int res = 0;
        //if we use int, the result of right shift of negative number
        //  is implementation-defined.
        for (unsigned tmp = a ^ b; tmp; tmp >>= 1) res += tmp & 0x1;
        return res;
    }
};

class Solution2 
{
public:
    int bitSwapRequired(int a, int b) 
    {
        int res = 0, tmp = a ^ b;
        while (tmp)
        {
            res++;
            tmp = tmp & (tmp - 1);
        }
        return res;
    }
};

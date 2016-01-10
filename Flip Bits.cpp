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
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) 
    {
        // write your code here
        int res = 0;
        //if we use int, the most left bit will always be 1 if a is
        //  positive and b is negative.
        for (unsigned tmp = a ^ b; tmp; tmp >>= 1) res += tmp & 0x1;
        return res;
    }
};
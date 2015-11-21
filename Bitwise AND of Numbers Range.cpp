/*
    Given a range [m, n] where 0 <= m <= n <= 2147483647, return 
        the bitwise AND of all numbers in this range, inclusive.

    For example, given the range [5, 7], you should return 4.
*/

//The idea is to find the first different bit. The all following
//  bits should be 0.
class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        if ( n == 0 ) return 0;
        if ( m == n ) return m;
        int res = 0;
        int toggle = (1 << 30);
        while (!(m & toggle) && !(n & toggle))
        {
            toggle >>= 1;
        }
        while (bool(m & toggle) == bool(n & toggle))
        {
            res |= (toggle & m);
            toggle >>= 1;
        }
        return res;
    }
};

//It's the same idea, but much simpler.
class Solution2
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int i = 0;
        for(; m != n; m >= 1, n >=1) ++i;
        return m << i;
    }
};
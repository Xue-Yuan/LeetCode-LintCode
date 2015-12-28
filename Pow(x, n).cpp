/*
    Implement pow(x, n).
*/

//overflow avoided
class Solution 
{
public:
    double myPow(double x, int n) 
    {
        long long m = n;
        if(m < 0) m = -m;
        double result = 1;
        while(m)
        {
            if(m & 0x1)
                result *= x;
            x *= x;
            m >>= 1;
        }
        if(n < 0) return 1.0 / result;
        return result;
    }
};

//haven't considered overflow.
class Solution2 
{
public:
    double myPow(double x, int n) 
    {
        if (n == 0) return 1;
        if (n < 0)
        {
            n = -n;
            x = 1.0 / x;
        }
        return n & 0x1 ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
    }
};
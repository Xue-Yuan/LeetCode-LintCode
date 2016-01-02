/*
    Implement int sqrt(int x).

    Compute and return the square root of x.
*/

class Solution
{
public:
    int mySqrt(int x)
    {
        int beg = 1, end = x;
        while (beg <= end)
        {
            long long mid = beg + ((end - beg) >> 1);
            long long tmp = mid * mid;
            if (tmp == x) return mid;
            if (tmp < x) beg = mid + 1;
            else end = mid - 1;
        }
        return end;
    }
};

class Solution2
{
public:
    int mySqrt(int x) 
    {
        if(x == 0) return 0;
        long long res = 0;
        int toggler = 1 << 16;
        while(toggler)
        {
            res |= toggler;
            if(res * res > x) res ^= toggler;
            toggler >>= 1;
        }
        return res;
    } 
};

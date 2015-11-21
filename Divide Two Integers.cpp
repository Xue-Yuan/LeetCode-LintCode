/*
    Divide two integers without using multiplication, 
        division and mod operator.

    If it is overflow, return MAX_INT.
*/
class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
    	if(! divisor) return INT_MAX;
        long long x = dividend, y = divisor;
        bool sign = (x & 0x80000000) ^ (y & 0x80000000);
        x = labs(x);
        y = labs(y);
        long long ans = 0; 
        long long bit_set = 1; 
        for(int i = 31; i >= 0; i--)  
        { 
        	bit_set = 1; 
            if((x>>i)>=y)  
            {  
                ans |= (bit_set<<i);        //Cannot just use (1 << i), otherwise ans will
                x -= (y<<i);                //  be interpreted into INT_MIN
            }  
        }  
		if((ans & 0x80000000) && !sign) return INT_MAX; 
        return sign ? -ans : ans; 
    }
};
/*
	Write an algorithm which computes the number of trailing zeros in 
		n factorial.

	Example
		11! = 39916800, so the out should be 2
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) 
    {
        long long cnt = 0;
        while (n) cnt += (n /= 5);
        return cnt;
    }
};

/*
    Given two 32-bit numbers, N and M, and two bit positions, i and j. 
        Write a method to set all bits between i and j in N equal to M 
        (e g , M becomes a substring of N located at i and starting at j)
*/

class Solution
{
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) 
    {
        // write your code here
    /*     bitwise not of (1s from j to the end) - (1s from i to the end) */

        long long tmp = 1, mask = ((tmp << (j - i + 1)) - 1) << i;
        return (n & ~mask ) | (m << i);
    }
};
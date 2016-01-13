/*
    Given string A representative a positive integer which has N 
        digits, remove any k digits of the number, the remaining 
        digits are arranged according to the original order to 
        become a new positive integer.

    Find the smallest integer after remove k digits.

    N <= 240 and k <= N,

    Example
        Given an integer A = "178542", k = 4

        return a string "12"
*/

class Solution 
{
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) 
    {
        // wirte your code here
        if (k == A.size()) return "0";
        int idx;
        for (int i = 0; i < k; ++i)
        {
            for (idx = 0; idx < (int)A.size() - 1; ++idx)
                if (A[idx] > A[idx + 1]) break;
            A.erase(idx, 1);
        }
        idx = 0;
        while (idx < A.size() && A[idx] == '0') idx++;
        return A.substr(idx);
    }
};

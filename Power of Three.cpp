/*
	Given an integer, write a function to determine if it is a power 
		of three.

	Follow up:
		Could you do it without using any loop / recursion?
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        
        while (n > 1)
        {
            if (n % 3 != 0) return false;
            n /= 3;
        }
        return n == 1;
    }
};

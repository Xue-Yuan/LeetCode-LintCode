/*
    Determine whether an integer is a palindrome. Do this without 
        extra space.
*/

//10000021
class Solution 
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        
        long long tmp = x, i = 1;
        while(i * 10 <= tmp)
            i *= 10;
        while(i >= 10)
        {
            if(tmp / i != tmp % 10)
                return false;
            tmp = tmp % i / 10;
            i /= 100;
        }
        return true;
    }
};

class Solution_2 
{
public:
    bool isPalindrome(int x) 
    {
        if(x < 0 || (x != 0 && x % 10==0)) 
            return false;
        int sum = 0;
        while(x > sum)
        {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return (x == sum) || (x == sum / 10);
    }
};
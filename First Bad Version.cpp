/*
    You are a product manager and currently leading a team 
        to develop a new product. Unfortunately, the latest 
        version of your product fails the quality check. 
        Since each version is developed based on the previous 
        version, all the versions after a bad version are 
        also bad.

    Suppose you have n versions [1, 2, ..., n] and you want 
        to find out the first bad one, which causes all the 
        following ones to be bad.

    You are given an API bool isBadVersion(version) which will 
        return whether version is bad. Implement a function to 
        find the first bad version. You should minimize the 
        number of calls to the API.
*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

//Just another lower_bound search.
class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        int b = 1, e = n;
        while (b < e)
        {
            int m = b + (e - b) / 2;
            if (!isBadVersion(m)) b = m + 1;
            else e = m;
        }
        return b;
    }
};

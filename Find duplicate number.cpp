/*
    Given an array nums containing n + 1 integers where each integer 
        is between 1 and n (inclusive), prove that at least one duplicate 
        number must exist. Assume that there is only one duplicate number, 
        find the duplicate one.

    Note:
        You must not modify the array (assume the array is read only).
        You must use only constant, O(1) extra space.
        Your runtime complexity should be less than O(n2).
        There is only one duplicate number in the array, but it could 
            be repeated more than once.
*/

/*
    The main trick is to notice that because
    we have an array of n elements ranging from 0 to n - 2, we can think of the
    array as defining a function f from the set {0, 1, ..., n - 1} onto itself.
    This function is defined by f(i) = A[i].  Given this setup, a duplicated
    value corresponds to a pair of indices i != j such that f(i) = f(j).  Our
    challenge, therefore, is to find this pair (i, j).  Once we have it, we can
    easily find the duplicated value by just picking f(i) = A[i].
*/

//http://keithschwarz.com/interesting/code/find-duplicate/FindDuplicate.python.html
    
class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int p = nums[0], q = nums[0];
        while(true)
        {
            q = nums[nums[q]];
            p = nums[p];
            if(q == p) break;
        }
        
        p = nums[0];
        while(p != q)
        {
            p = nums[p];
            q = nums[q];
        }
        return p;
    }
};
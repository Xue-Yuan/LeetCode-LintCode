/*
    Follow up for "Find Minimum in Rotated Sorted Array":
    What if duplicates are allowed?

    Would this affect the run-time complexity? How and why?

    Suppose a sorted array is rotated at some pivot unknown to you 
        beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    Find the minimum element.

    The array may contain duplicates.
*/

/*
    Suppose the array contains all the same elements, then the run
        time will be O(n).
*/

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int b = 0, e = (int)nums.size() - 1;
        while(b < e)
        {
            if (nums[b] < nums[e]) return nums[b];
            if (b + 1 == e) return min(nums[b], nums[e]);
            int m = b + (e - b) / 2;
            if (nums[b] < nums[m]) b = m + 1;
            else if (nums[e] > nums[m]) e = m;
            while (nums[b] == nums[m] && b != m) b++;
            while (nums[e] == nums[m] && e != m) e--;
        }
        return nums[b];
    }
};
/*
    Follow up for "Search in Rotated Sorted Array":
    What if duplicates are allowed?

    Would this affect the run-time complexity? How and why?

    Write a function to determine if a given target is in 
        the array.
*/

//find min, then go with binary search
class Solution
{
private:
    bool search(vector<int>&nums, int b, int e, int target)
    {
        if(b > e) return false;
        if(b == e) return nums[b] == target;
        
        int mid = b + ((e - b) >> 1);
        if(target == nums[mid]) return true;
        return search(nums, b, mid - 1, target) || search(nums, mid + 1, e, target);
        
    }
public:
    bool search(vector<int>& nums, int target)
    {
        int mid = findMin(nums);
        return search(nums, 0, mid, target) || search(nums, mid + 1, nums.size() - 1, target);
    }
    
    int findMin(vector<int>& nums)
    {
        int b = 0, e = nums.size() - 1;
        while(b < e)
        {
            int m = b + ((e - b) >> 1);
            if(nums[b] < nums[e])
                return b;
            if(nums[m] > nums[e])
                b = m + 1;
            else if(nums[b] > nums[m])
                e = m;
            else
            {
                while(b < e && nums[m] == nums[e])
                    --e;
                while(b < e && nums[b] == nums[m])
                    ++b;
            }
        }
        return b;
    }
};

//Copy from the discusion
class Solution2 
{
public:
    bool search(vector<int> &A, int target) 
    {
        int lo = 0, hi = A.size() - 1;
        int mid = 0;
        
        while(lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            
            if(A[mid] == target) return true;
            if(A[mid] > A[hi])
            {
                if(A[mid] > target && A[lo] <= target) hi = mid;
                else lo = mid + 1;
            }
            else if(A[mid] < A[hi])
            {
                if(A[mid] < target && A[hi] >= target) lo = mid + 1;
                else hi = mid;
            }
            else
            {
                hi--;
            }
        }
        return false;
    }
};
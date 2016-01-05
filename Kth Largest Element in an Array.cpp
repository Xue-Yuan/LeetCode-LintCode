/*
	Find the kth largest element in an unsorted array. Note that it 
		is the kth largest element in the sorted order, not the kth 
		distinct element.

	For example,
		Given [3,2,1,5,6,4] and k = 2, return 5.

	Note: 
		You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};

class Solution2
{
private:
    int &median3(vector<int> &nums, int b, int e)
    {
        int m = b + ((e - b) >> 1);
        if (nums[b] < nums[m]) swap(nums[b], nums[m]);
        if (nums[b] < nums[e]) swap(nums[b], nums[e]);
        if (nums[e] < nums[m]) swap(nums[e], nums[m]);
        return nums[e];		//pay attention here
    }

    int findKthLargest(vector<int> &nums, int b, int e, int k)
    {
        if (b >= e) return nums[b];	//pay attention here
        if (b + 1 == e)	//pay attention here
        {
            if (nums[b] < nums[e]) swap(nums[b], nums[e]);
            return nums[k - 1];
        }
        int &pivot = median3(nums, b, e);
        int i = b, j = e;
        while (i < j)
        {
            while (nums[++i] > pivot);
            while (nums[--j] < pivot);
            if (i < j) swap(nums[i], nums[j]);
        }
        swap(nums[i], pivot);
        if (i == k - 1) return nums[i];
        if (i > k - 1) return findKthLargest(nums, b, i - 1, k);
        return findKthLargest(nums, i + 1, e, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        return findKthLargest(nums, 0, (int)nums.size() - 1, k);
    }
};

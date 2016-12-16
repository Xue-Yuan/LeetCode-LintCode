/*
	Given an unsorted array nums, reorder it such that 
		nums[0] < nums[1] > nums[2] < nums[3]....

	Example:
		(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is 
			[1, 4, 1, 5, 1, 6]. 
		(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is 
			[2, 3, 1, 3, 1, 2].

	Note:
		You may assume all input has valid answer.

	Follow Up:
		Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

//O(nlogn) time, O(n) space
//4,5,5,6
class Solution
{
public:
    void wiggleSort(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> tmp(nums.size());
        int b1 = 0, b2 = (int)nums.size() / 2;
        for (int i = 0; i < nums.size(); ++i)
            tmp[i] = i & 0x1 ? nums[b1++] : nums[b2++];
        nums = move(tmp);
    }
};


//Three-way-partition
class Solution2 {
public:
    void wiggleSort(vector<int>& nums) {
        int sz = (int)nums.size();
        nth_element(nums.begin(), nums.begin()+sz/2, nums.end());
        int mid = nums[sz/2];
        int i = 0, j = 0, k = sz-1;
        while (j <= k) {
            if (nums[j] > mid) {
                swap(nums[i++], nums[j++]);
            } else if (nums[j] < mid) {
                swap(nums[j], nums[k--]);
            } else {
                ++j;
            }
        }
        vector<int> tmp(sz, 0);
        for (int i = 0, sm = sz/2; i < sz; i += 2) {
            tmp[i] = nums[sm++];
        }
        for (int i = 1, lg = 0; i < sz; i += 2) {
            tmp[i] = nums[lg++];
        }
        nums = move(tmp);
    }
};

//https://leetcode.com/discuss/77133/o-n-o-1-after-median-virtual-indexing

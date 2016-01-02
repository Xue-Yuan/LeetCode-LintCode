class Solution
{
public: 
    void wiggleSort(vector<int>& nums)
    {
        for (int i = 1; i < nums.size(); i++)
        	//odd: nums[i] >= nums[i - 1]
        	//even: nums[i] <= nums[i - 1]
            if (i % 2 == (nums[i-1] > nums[i])) 
                swap(nums[i], nums[i - 1]);
    } 
};
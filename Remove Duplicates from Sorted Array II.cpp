/*
    Follow up for "Remove Duplicates":
    What if duplicates are allowed at most twice?

    For example,
    Given sorted array nums = [1,1,1,2,2,3],

    Your function should return length = 5, with the first five 
        elements of nums being 1, 1, 2, 2 and 3. It doesn't matter 
        what you leave beyond the new length.
*/
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() < 3) return nums.size();
        
        int cur = 1, cnt = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == nums[i - 1])
                ++cnt;
            else
                cnt = 1;
            if(cnt < 3)
                nums[cur++] = nums[i];
        }
        
        for(auto &e : nums)
            cout << e << ' ';
        cout << endl;
        return cur;
    }
};
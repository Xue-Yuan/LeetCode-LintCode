/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
//http://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/
//Not a good way to list all results. For one result, it's good enough.
class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<twoSum> aux(nums.size()* (nums.size() - 1) / 2);
        vector<vector<int>> ret;
        
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            for(int j = i + 1; j < nums.size(); --j)
            {
                aux[i * nums.size() + j].sum = nums[i] + nums[j];
                aux[i * nums.size() + j].first = i;
                aux[i * nums.size() + j].second = j;
            }
        }
        sort(aux.begin(), aux.end(), [](twoSum &lt, twoSum &rt){return lt.sum < rt.sum;});
        int beg = 0, end = aux.size() - 1;
        while(beg < end)
        {
            if(aux[beg].sum + aux[end].sum == target)
            {
                if(!aux[beg].hasCommon(aux[end]))
                {
                    vector<int> v = {nums[aux[beg].first], nums[aux[beg].second], nums[aux[end].first], nums[aux[end].second]};
                    sort.(v.begin(), v.end());
                    ret.push_back(v);
                }
            }
            else if(aux[beg].sum + aux[end].sum > target)
                --end;
            else
                ++beg;
        }
        return ret;
    }
    
    struct twoSum
    {
        int sum;
        int first;
        int second;
        bool hasCommon(twoSum &op2)
        {
            return first == op2.first || first == op2.second || second == op2.first || second == op2.second; 
        }
    };
};

/*
    This is more standard solution
*/
class Solution2
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int i = 0; i < nums.size() - 3; ++i)
        {
            if(i != 0 && nums[i] == nums[i - 1]) continue;     //avoid duplicates
            
            for(int j = i + 1; j < nums.size() - 2; ++j)
            {
                if(j != i + 1 && nums[j] == nums[j - 1]) continue;
                
                int twoSum = target - nums[i] - nums[j];
                
                int left = j + 1, right = nums.size() - 1;
                
                while(left < right)
                {
                    if(nums[left] + nums[right] == twoSum)
                    {
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(right > left && nums[right] == nums[right - 1]) --right;
                        while(right > left && nums[left] == nums[left + 1]) ++left;
                        ++left;
                        --right;
                    }
                    else if(nums[left] + nums[right] > twoSum) --right;
                    else ++left;
                }
            }
        }
        return ret;
    }
};
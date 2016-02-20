class Solution
{
public:
	int maximumSubarray(vector<int> &nums, int k)
	{
		unordered_map<int, int> m;
		m[0] = -1;
		int n_sz = (int)nums.size(), sum = 0, res = -1;
		for (int i = 0; i < n_sz; ++i)
		{
			sum += nums[i];
			if (m.find(sum-k) != m.end())
				res = max(res, i-m[sum-k]);
			if (m.find(sum) == m.end())
				m[sum] = i;
		}
		return res;
	}
};

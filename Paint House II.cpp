/*
	There are a row of n houses, each house can be painted with one of 
		the k colors. The cost of painting each house with a certain 
		color is different. You have to paint all the houses such that 
		no two adjacent houses have the same color.

	The cost of painting each house with a certain color is represented 
		by a n x k cost matrix. For example, costs[0][0] is the cost of 
		painting house 0 with color 0; costs[1][2] is the cost of painting 
		house 1 with color 2, and so on... Find the minimum cost to paint 
		all houses.

	Note:
		All costs are positive integers.

	Follow up:
		Could you solve it in O(nk) runtime?
*/

class Solution
{
public:
	int minCost(vector<vector<int>> &cost)
	{
		if (cost.empty() || cost[0].empty()) return 0;

		vector<vector<int>> dp(cost.size(), vector<int>(cost.front().size()));
		dp[0] = cost[0];

		for (size_t i = 1; i < cost.size(); ++i)
		{
			for (size_t cur = 0; cur < cost[0].size(); ++cur)
			{
				dp[i][cur] = INT_MAX;
				for (size_t pre = 0; pre < cost[0].size(); ++pre)
				{
					if (cur == pre) continue;
					dp[i][cur] = min(dp[i][cur], dp[i-1][pre]+cost[i][cur]);
				}
			}
		}
		return *min_element(dp.back().begin(), dp.back().end());
	}
};

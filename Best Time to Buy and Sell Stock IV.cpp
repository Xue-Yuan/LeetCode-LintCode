/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include <vector>

using std::vector;

class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        if(prices.size() < 2) return 0;
        if(k >= prices.size())      //this is the same as however many times you want
        {
            int mi = prices[0], res = 0;
            for(auto &p : prices)
            {
                mi = min(mi, p);
                res = max(res, p - mi);
            }
            return res;
        }
        

        
        vector<vector<int>> states(2, vector<int>(2 * k, INT_MIN));
        for(auto &v : states)
        	for(int i = 0; i < v.size(); ++i)
        		if(i & 0x1) v[i] = 0;
        
        int cur = 0, next = 1;
        for(auto &p : prices)
        {
            for(int i = 0; i < 2*k; ++i)
            {
                if(i == 0) 
                {
                    states[next][i] = max(states[cur][i], -p);
                    continue;
                }
                if(i & 0x1) states[next][i] = max(states[cur][i], states[cur][i-1] + p);
                else
                {
                    states[next][i] = max(states[cur][i], states[cur][i - 1] - p);
                }
            }
            swap(next, cur);
        }
        return states[cur][2*k - 1];
    }
};
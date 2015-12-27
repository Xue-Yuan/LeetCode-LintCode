/*
    Say you have an array for which the ith element is the price of a given stock on day i.

    Design an algorithm to find the maximum profit. You may complete at most two transactions.

*/
/*
    From left to right, we can find max profit by one transaction.
    From right to left, we find another one.
*/
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() < 2) return 0;
        
        vector<int> p_left(prices.size(), 0);
        
        //left to right
        int mi = prices[0], max_sofar = 0;
        for(int i = 0; i < prices.size(); ++i)
        {
            mi = min(mi, prices[i]);
            max_sofar = max(max_sofar, prices[i] - mi);
            p_left[i] = max_sofar;
        }

        //right to left
        int ret = 0, ma = prices[prices.size() - 1];
        max_sofar = 0;
        for(int i = prices.size() - 1; i >= 0; --i)
        {
            ma = max(prices[i], ma);
            max_sofar = max(max_sofar, ma - prices[i]);
            ret = max(ret, max_sofar + p_left[i]);
        }
        return ret;
    }

    /*
        This solution is from LeetCode discussion.
    */
    int maxProfit2(vector<int>& prices) 
    {
        /*
            0: 1 buy
            1: one buy/sell, 
            2: 2 buys/1 sell, 
            3, 2 buys/sells
        */
        int states[2][4]{INT_MIN, 0, INT_MIN, 0}; 
        int len = prices.size(), i, cur = 0, next =1;
        for(i=0; i<len; ++i)
        {
            states[next][0] = max(states[cur][0], -prices[i]);
            states[next][1] = max(states[cur][1], states[cur][0]+prices[i]);
            states[next][2] = max(states[cur][2], states[cur][1]-prices[i]);
            states[next][3] = max(states[cur][3], states[cur][2]+prices[i]);
            swap(next, cur);
        }
        return max(states[cur][1], states[cur][3]);
    }
};
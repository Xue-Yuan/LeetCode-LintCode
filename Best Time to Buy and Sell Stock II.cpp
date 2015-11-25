/*
    Say you have an array for which the ith element is the price of a given 
        stock on day i.

    Design an algorithm to find the maximum profit. You may complete as many 
        transactions as you like (ie, buy one and sell one share of the stock 
        multiple times). However, you may not engage in multiple transactions 
        at the same time (ie, you must sell the stock before you buy again).
*/

/*
 states:
     buy  => able to buy
     sell => able to sell
 */
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        const int buy = 0, sell = 1;
        int cur = 0, next = 1;
        vector<vector<int>> states(2, vector<int>(2, 0));
        
        states[cur][sell] = INT_MIN;
        //actually it's better to manually control the first
        //  transaction to avoid sell before buy. But with
        //  the initial states INI_MIN, we are safe here.
        for(int &p : prices)
        {
            states[next][buy] = max(states[cur][buy], states[cur][sell] + p);
            states[next][sell] = max(states[cur][buy] - p, states[cur][sell]);
        }
        return states[cur][buy];
    }
};

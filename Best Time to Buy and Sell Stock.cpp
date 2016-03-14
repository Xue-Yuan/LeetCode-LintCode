/*
    Say you have an array for which the ith element is the price of a given stock 
        on day i.

    If you were only permitted to complete at most one transaction (ie, buy one 
        and sell one share of the stock), design an algorithm to find the maximum 
        profit.
*/
        
/*
 states:
     buy  => able to buy
     sell => able to sell
     end => end of transaction
 */
class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        if (prices.empty()) return 0;
        
        int buy = prices[0], max_profit = 0;
        for (int &p : prices)
        {
            buy = min(buy, p);
            max_profit = max(max_profit, p-buy);
        }
        return max_profit;
    }
};

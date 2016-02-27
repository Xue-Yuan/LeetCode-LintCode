/*
    Say you have an array for which the ith element is the price of a given stock on day i.

    Design an algorithm to find the maximum profit. You may complete as many transactions 
        as you like (ie, buy one and sell one share of the stock multiple times) with the 
        following restrictions:

    You may not engage in multiple transactions at the same time (ie, you must sell the 
        stock before you buy again).
    
    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
    
    Example:

        prices = [1, 2, 3, 0, 2]
        maxProfit = 3
        transactions = [buy, sell, cooldown, buy, sell]
*/

/*
 states:
     buy  => able to buy
     sell => able to sell
     cool => cool down state

     sell <--(buy)-- buy
       \             ^
        \           /
      (sell)    (auto)
         \        /
          \      /
           v    /
            cool
 */ 
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        const int buy = 0, sell = 1, cool = 2;
        int cur = 0, next = 1;
        
        vector<vector<int>> states(2, vector<int>(3, 0));
        states[cur][sell] = INT_MIN;
        
        for(int &p : prices)
        {
            states[next][buy] = max(states[cur][buy], states[cur][cool]);
            states[next][sell] = max(states[cur][sell], states[cur][buy] - p);
            states[next][cool] = states[cur][sell] + p;
            swap(next, cur);
        }
        return max(states[cur][buy], states[cur][cool]);
    }
};

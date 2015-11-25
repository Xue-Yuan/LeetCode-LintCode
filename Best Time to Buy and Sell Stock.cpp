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
    int maxProfit(vector<int>& prices)
    {
        const int buy = 0, sell = 1, end = 2;
        int cur = 0, next = 1;
        vector<vector<int>> states(2, vector<int>(3, 0));
        states[cur][sell] = INT_MIN;
        
        for(int &p : prices)
        {
            states[next][buy] = states[cur][buy];
            states[next][sell] = max(states[cur][buy] - p, states[cur][sell]);
            states[next][end] = max(states[cur][sell] + p, states[cur][end]);
            swap(cur, next);
        }
        return states[cur][end];
    }
};
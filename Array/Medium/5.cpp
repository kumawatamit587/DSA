class Solution
{
    // https://takeuforward.org/data-structure/stock-buy-and-sell/
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = INT_MIN;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit > 0 ? maxProfit : 0;
    }
};

///////////
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < buy)
            {
                buy = prices[i];
            }
            else
            {
                profit = max(profit, prices[i] - buy);
            }
        }
        return profit;
    }
};
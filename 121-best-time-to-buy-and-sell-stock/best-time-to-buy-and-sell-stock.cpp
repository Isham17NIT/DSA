class Solution 
{
private:
    void findMaxProfit(int idx,int minBuy,int &maxProfit,vector<int> &prices)
    {
        if(idx==prices.size())
            return;
        //sell
        int profit = prices[idx] - minBuy;
        maxProfit = max(maxProfit, profit);

        //buy
        findMaxProfit(idx+1,min(minBuy,prices[idx]),maxProfit,prices);
        return;
    }
public:
    int maxProfit(vector<int>& prices) 
    {
        int minBuy = prices[0]; //minm buy price
        int maxProfit = 0;
        findMaxProfit(1,minBuy,maxProfit,prices);
        return maxProfit;
    }
};
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        vector<int> nextGreatestPrice(prices.size());
        int maxProfit=0;
        for(int i=prices.size()-1;i>=0;i--)
        {
            if(i==prices.size()-1 || prices[i]>=nextGreatestPrice[i+1])
                nextGreatestPrice[i]=prices[i];
            else
                nextGreatestPrice[i]=nextGreatestPrice[i+1];                
        }
        for(int i=0;i<prices.size();i++)
        {
            maxProfit=max(maxProfit, nextGreatestPrice[i]-prices[i]);
        }
        return maxProfit;
    }
};
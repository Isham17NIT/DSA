class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<int> nextRow(2,0);
        for(int idx=n-1;idx>=0;idx--)
        {
            vector<int> currRow(2);
            for(int buy=0;buy<2;buy++)
            {
                int p1 = nextRow[buy]; //do nothing
                int p2=0;
                if(buy==0)
                    p2 = prices[idx] + nextRow[1];
                else
                    p2 = -prices[idx] + nextRow[0];
                currRow[buy] = max(p1, p2);
            }
            nextRow = currRow;
        }
        return nextRow[1];
    }
};
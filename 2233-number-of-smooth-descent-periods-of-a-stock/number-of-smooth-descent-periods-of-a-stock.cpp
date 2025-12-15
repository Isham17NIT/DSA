class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) 
    {
        long long ans=prices.size(); // a period with 1 day is a smooth descent period by defn
        int start=-1;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]+1==prices[i-1])
            {
                if(start==-1)
                    start=i-1;
            }
            else
            {
                if(start==-1)
                    continue;
                int n=i-start;
                ans=ans+((long long)n*(long long)(n-1)/2); //subarrays with size > 1 added
                start=-1;
            }
        }
        if(start!=-1) //subarray which finishes at the last idx
        {
            int n=prices.size()-start;
            ans=ans+((long long)n*(long long)(n-1)/2); //subarrays with size > 1 added
        }
        return ans;
    }
};
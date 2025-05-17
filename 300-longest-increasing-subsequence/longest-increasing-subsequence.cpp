class Solution 
{
public:
    int lengthOfLIS(vector<int>& infoUnits) 
    {
        int n=infoUnits.size();
        vector<int> nextRow(n,0);
        nextRow[0] = 1;
        
        for(int prev=1;prev<n;prev++)
        {
            if(infoUnits[n-1] > infoUnits[prev-1])
                nextRow[prev] = 1;
            else
                nextRow[prev] = 0;
        }
        for(int idx=n-1;idx>=1;idx--)
        {
            vector<int> currRow(n,0);
            for(int prev=n-1;prev>=0;prev--)
            {
                if(prev==0 || infoUnits[idx-1] > infoUnits[prev-1])
                {
                    int report = 1 + nextRow[idx];
                    int notReport = nextRow[prev];
                    currRow[prev] = max(report, notReport);
                }
                else
                {
                    currRow[prev] = nextRow[prev];
                }
            }
            nextRow=currRow;
        }
        return nextRow[0];
    }
};
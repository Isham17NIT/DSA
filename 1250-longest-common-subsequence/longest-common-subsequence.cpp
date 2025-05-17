class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m=text1.size();
        int n=text2.size();
        vector<int> prevRow(n+1);
        for(int i=0;i<=n;i++)
        {
            prevRow[i]=0;
        }
        for(int idx1=1;idx1<=m;idx1++)
        {
            vector<int> currRow(n+1);
            currRow[0]=0;
            for(int idx2=1;idx2<=n;idx2++)
            {
                if(text1[idx1-1]==text2[idx2-1])
                    currRow[idx2] = 1 + prevRow[idx2-1];
                else
                {
                    currRow[idx2] = max(prevRow[idx2], currRow[idx2-1]);
                }
            }
            prevRow=currRow;
        }
        return prevRow[n];
    }
};
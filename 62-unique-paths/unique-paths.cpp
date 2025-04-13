class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        vector<int> prevRow(n,1);
        vector<int> currRow(n,0);

        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                    currRow[j] = prevRow[j];
                else
                    currRow[j] = currRow[j-1] + prevRow[j];
            }
            prevRow = currRow;
        }
        return prevRow[n-1];
    }
};
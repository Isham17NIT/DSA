class Solution 
{
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) 
    {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> prefix(m, vector<int>(n, 0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    prefix[0][0] = mat[0][0];
                else if(i==0)
                    prefix[0][j] = prefix[0][j-1] + mat[i][j];
                else if(j==0)
                    prefix[i][0] = prefix[i-1][0] + mat[i][j];
                else
                    prefix[i][j] = mat[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }

        for(int offset = min(m,n) - 1;offset >= 0; offset--)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    // i, j represent top left coordinates
                    if(i+offset < m && j+offset < n)
                    {
                        // calculate squareSum
                        int squareSum = prefix[i+offset][j+offset] 
                            - (j>0 ? prefix[i+offset][j-1] : 0) 
                            - (i>0 ? prefix[i-1][j+offset] : 0) 
                            + ((i>0 && j>0) ? prefix[i-1][j-1] : 0);
                        
                        if(squareSum <= threshold)
                            return offset+1;
                    }
                    else
                        break;
                }
            }
        }
        return 0;
    }
};
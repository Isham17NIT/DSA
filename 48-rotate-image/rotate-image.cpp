class Solution 
{
public:
    void rotate(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        if(n==1)
            return;
        //first find transpose
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int j=0;j<n/2;j++)
        {
            for(int i=0;i<n;i++)
            {
                swap(mat[i][j],mat[i][n-j-1]);
            }
        }
        return;
    }
};
class Solution 
{
public:
    void rotate(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        if(n==1)
            return;
        //first find transpose
        for(int i=1;i<n;i++)
        {
            int j=i; //row no
            int k=0; //col no
            int numOfSwaps = 0;
            while(numOfSwaps < floor((i+1)/2))
            {
                swap(mat[j][k],mat[k][j]);
                j--; k++;
                numOfSwaps++;
            }
        }
        for(int i=1;i<n-1;i++)
        {
            int j=i; //row no
            int k=n-1; //col no
            int numOfSwaps = 0;
            while(numOfSwaps < floor((n-i)/2))
            {
                swap(mat[j][k],mat[k][j]);
                j++; k--;
                numOfSwaps++;
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
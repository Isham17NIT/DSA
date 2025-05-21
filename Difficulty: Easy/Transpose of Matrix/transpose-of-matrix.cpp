class Solution {
  public:
    // Function to find transpose of a matrix.
    void transpose(vector<vector<int>>& mat, int n) 
    {
        if(n==1)
            return;
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
        return;
    }
};
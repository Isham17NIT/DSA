class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        vector<int> ans;
        int dir=1; //0---->down, 1---->up
        int m=mat.size(), n=mat[0].size();

        int i=0, j=0;
        while(ans.size()<m*n)
        {
            if(dir)
            {
                while(i>=0 && j<n)
                {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                if(j==n)
                {
                    i+=2;
                    j=n-1;
                }  
                else
                    i+=1; 
            }
            else
            {
                while(i<m && j>=0)
                {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                if(i==m){
                    i=m-1;
                    j+=2;
                }
                else
                    j+=1;
            }
            dir=!dir;
        }
        return ans;
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int col=1;
        int r=matrix.size(), c=matrix[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(j==0){
                        col = 0;
                    }
                    else{
                        matrix[0][j] = 0;
                    }
                    matrix[i][0] = 0;
                }               
            }
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                    matrix[i][j] = 0;
            }
        }
        for(int j=1;j<c;j++)
        {
            if(matrix[0][0]==0)
                matrix[0][j] = 0;
        }
        for(int i=0;i<r;i++)
        {
            if(col==0)
                matrix[i][0] = 0;
        }
    }
};
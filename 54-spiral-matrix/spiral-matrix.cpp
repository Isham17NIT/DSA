class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int minRow=0, minCol=0, maxRow=m-1, maxCol=n-1;
        while(minRow<=maxRow && minCol<=maxCol)
        {
            for(int i=minCol;i<=maxCol;i++)
            {
                ans.push_back(matrix[minRow][i]);
            }
            minRow++;
            for(int i=minRow;i<=maxRow;i++)
            {
                ans.push_back(matrix[i][maxCol]);
            }
            maxCol--;
            if(minRow <= maxRow)
            {
                for(int i=maxCol;i>=minCol;i--)
                {
                    ans.push_back(matrix[maxRow][i]);
                }
                maxRow--;
            }        
            if(minCol <= maxCol)
            {
                for(int i=maxRow;i>=minRow;i--)
                {
                    ans.push_back(matrix[i][minCol]);
                }
                minCol++;
            }    
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(), n=matrix[0].size();
        int minRow=0, minCol=0, maxRow=m-1, maxCol=n-1;
        vector<int> ans;
        while(minRow<maxRow && minCol<maxCol)
        {
            for(int j=minCol;j<=maxCol;j++)
            {
                ans.push_back(matrix[minRow][j]);
            }
            minRow++;
            for(int i=minRow;i<=maxRow;i++)
            {
                ans.push_back(matrix[i][maxCol]);
            }
            maxCol--;
            if(minCol<maxCol)
            {
                for(int j=maxCol;j>=minCol;j--)
                {
                    ans.push_back(matrix[maxRow][j]);
                }
                maxRow--;
            }
            if(minRow<maxRow)
            {
                for(int i=maxRow;i>=minRow;i--)
                {
                    ans.push_back(matrix[i][minCol]);
                }
                minCol++;
            }
        }
        if(minRow==maxRow && minCol==maxCol)
            ans.push_back(matrix[minRow][minCol]);
        else if(minRow==maxRow)
        {
            for(int j=minCol;j<=maxCol;j++){
                ans.push_back(matrix[minRow][j]);
            }
        }
        else if(minCol==maxCol)
        {
            for(int j=minRow;j<=maxRow;j++){
                ans.push_back(matrix[j][minCol]);
            }
        }
        return ans;
    }
};
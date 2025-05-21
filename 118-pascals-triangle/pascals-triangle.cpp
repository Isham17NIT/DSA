class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans(numRows,vector<int>());
        ans[0]={1};
        if(numRows==1)
            return ans;
        ans[1]={1,1};
        if(numRows>2)   
        {
            for(int row=2;row<numRows;row++)
            {
                ans[row]=vector<int>(row+1);
                ans[row][0]=1;
                ans[row][row]=1;
                for(int i=1;i<row;i++)
                {
                    ans[row][i]=ans[row-1][i-1] + ans[row-1][i];
                }
            }
        }
        return ans;
    }
};
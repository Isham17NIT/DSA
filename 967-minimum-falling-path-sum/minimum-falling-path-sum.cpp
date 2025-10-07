class Solution {
private:
    vector<vector<int>> dirs={{-1,-1},{-1,0},{-1,1}};
    bool isValid(int i,int j,int m,int n)
    {
        return i>=0 && j>=0 && i<m && j<n;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> prev(n,INT_MAX);
        int ans=INT_MAX;
        
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,INT_MAX);
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    curr[j]=matrix[i][j];
                    continue;
                }
                for(vector<int> dir : dirs)
                {
                    if(isValid(i+dir[0],j+dir[1],m,n))
                        curr[j]=min(curr[j], prev[j+dir[1]]);
                }
                curr[j]+=matrix[i][j];
            }
            prev=curr;
        }
        for(int j=0;j<n;j++)
        {
            ans=min(ans, prev[j]);
        }
        return ans;
    }
};
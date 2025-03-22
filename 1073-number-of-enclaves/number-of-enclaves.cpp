class Solution {
public:
    int rows[4]={-1,0,1,0};
    int cols[4]={0,1,0,-1};
    bool isValid(int i,int j,int m,int n,vector<vector<bool>> &visited,vector<vector<int>> &mat)
    {
        return i>=0 && i<m && j>=0 && j<n && mat[i][j]==1 && !visited[i][j];
    }
    void dfsVisit(vector<vector<int>>& mat,int i,int j,int m,int n,vector<vector<bool>> &visited)
    {
        visited[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int newRow=i+rows[k];
            int newCol=j+cols[k];
            if(isValid(newRow,newCol,m,n,visited,mat))
                dfsVisit(mat,newRow,newCol,m,n,visited);
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        //first row
        for(int j=0;j<n;j++)
        {
            if(mat[0][j]==1 && !visited[0][j])
                dfsVisit(mat,0,j,m,n,visited);
        }
        //last row
        for(int j=0;j<n;j++)
        {
            if(mat[m-1][j]==1 && !visited[m-1][j])
                dfsVisit(mat,m-1,j,m,n,visited);
        }
        //first col
        for(int i=0;i<m;i++)
        {
            if(mat[i][0]==1 && !visited[i][0])
                dfsVisit(mat,i,0,m,n,visited);
        }
        //last col
        for(int i=0;i<m;i++)
        {
            if(mat[i][n-1]==1 && !visited[i][n-1])
                dfsVisit(mat,i,n-1,m,n,visited);
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && mat[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
};
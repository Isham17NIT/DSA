class Solution 
{
public:
    void bfs(vector<vector<int>>&mat,int m,int n,vector<vector<bool>> &visited,queue<pair<int,int>> &q,vector<vector<int>>& distance)
    {
        while(!q.empty())
        {
            pair<int,int> curr = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newRow=curr.first+rows[i];
                int newCol=curr.second+cols[i];
                if(isValid(newRow,newCol,m,n,mat,visited))
                {
                    visited[newRow][newCol]=true;
                    distance[newRow][newCol]=distance[curr.first][curr.second]+1;
                    q.push({newRow,newCol});
                }
            }
        }
        return;
    }
    int rows[4]={-1,0,1,0};
    int cols[4]={0,1,0,-1};
    bool isValid(int i,int j,int m,int n,vector<vector<int>>& mat,vector<vector<bool>> &visited)
    {
        return i>=0 && i<m && j>=0 && j<n && mat[i][j]==1 && !visited[i][j];
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
       
        vector<vector<int>> distance(m,vector<int>(n,0));
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0) //look for it's 4 directionally adjacent ones
                {
                    visited[i][j]=true;
                    for(int k=0;k<4;k++)
                    {
                        int newRow=i+rows[k];
                        int newCol=j+cols[k];
                        if(isValid(newRow,newCol,m,n,mat,visited))
                        {
                            visited[newRow][newCol]=true;
                            distance[newRow][newCol]=1;
                            q.push({newRow,newCol});
                        }
                    }
                }
            }
        }

        bfs(mat,m,n,visited,q,distance);

        return distance;
    }
};
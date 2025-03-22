class Solution 
{
public:
    int rows[4]={-1,0,1,0};
    int cols[4]={0,1,0,-1};
    bool isValid(int i,int j,int m,int n,vector<vector<int>>& mat,vector<vector<int>> &distance)
    {
        return i>=0 && i<m && j>=0 && j<n && mat[i][j]==1 && distance[i][j]==-1;
    }
    void bfs(vector<vector<int>>&mat,int m,int n,queue<pair<int,int>> &q,vector<vector<int>>& distance)
    {
        while(!q.empty())
        {
            pair<int,int> curr = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newRow=curr.first+rows[i];
                int newCol=curr.second+cols[i];
                if(isValid(newRow,newCol,m,n,mat,distance))
                {
                    distance[newRow][newCol]=distance[curr.first][curr.second]+1;
                    q.push({newRow,newCol});
                }
            }
        }
        return;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
       
        vector<vector<int>> distance(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                }
                else
                {
                    distance[i][j]=-1;
                }
            }
        }

        bfs(mat,m,n,q,distance);

        return distance;
    }
};
class Solution {
public:
    int rows[4]={-1,0,1,0};
    int cols[4]={0,1,0,-1};
    bool isValid(int i,int j,int m,int n,vector<vector<bool>> &visited,vector<vector<char>> &grid)
    {
        return i>=0 && i<m && j>=0 && j<n && grid[i][j]=='1' && !visited[i][j];
    }
    void dfsVisit(vector<vector<char>>& mat,int i,int j,int m,int n,vector<vector<bool>> &visited)
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
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(); //rows
        int n=grid[0].size(); //cols
        int cnt=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    cnt++; //another connected component found
                    dfsVisit(grid,i,j,m,n,visited);
                }
            }
        }
        return cnt;
    }
};
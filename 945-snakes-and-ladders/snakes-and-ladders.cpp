class Solution {
private:
    pair<int,int> getCoordinates(int n,int x) //n->size of board and x is number
    {
        int row = n-1 - (x-1)/n;
        bool LtoR;
        int col;
        if((n%2==0 && row%2!=0) || (n%2!=0 && row%2==0))
            LtoR=true;
        else
            LtoR=false;
        if(LtoR)
            col=(x-1)%n;
        else
            col=(n-(x%n))%n;
        return {row,col};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n=board.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({1,0});
        visited[n-1][0]=true;
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            for(int i=p.first+1;i<=min(p.first+6,n*n);i++)
            {
                pair<int,int> c = getCoordinates(n,i);
                int neighbor = board[c.first][c.second]!=-1 ? board[c.first][c.second] : i;
                pair<int,int> ng = getCoordinates(n,neighbor);
                if(!visited[ng.first][ng.second])
                {
                    visited[ng.first][ng.second]=true;
                    q.push({neighbor, p.second+1});
                    if(neighbor==n*n)
                        return p.second+1;
                }
            }
        }
        return -1;
    }
};
class Solution {
private:
    int rows[8] = {-1,-1,0,1,1,1,0,-1};
    int cols[8] = {0,1,1,1,0,-1,-1,-1};
    bool isValid(int i,int j,int m,int n)
    {
        return i>=0 && j>=0 && i<m && j<n;
    }
    int applyRules(vector<vector<int>>& board,int i,int j)
    {
        int m=board.size(), n=board[0].size();
        int cnt=0; //no. of live neighbors
        for(int k=0;k<8;k++)
        {
            int newRow = i+rows[k];
            int newCol = j+cols[k];
            if(isValid(newRow, newCol, m, n) && board[newRow][newCol]&1)
                cnt++;
        }
        if((board[i][j]&1) == 0){
            if(cnt==3)
                return 1;
            else
                return 0;
        }
        //else -->board[i][j]==1
        if(cnt>3 || cnt<2)
            return 0;
        return 1;
    }
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int m=board.size(), n=board[0].size();
        // 2 bits --> newState currState
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j] |= (applyRules(board,i,j) << 1);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j] >>= 1;
            }
        }
    }
};
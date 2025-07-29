class Solution {
private: 
    int rows[4]={-1,0,1,0};
    int cols[4]={0,1,0,-1};
    bool isValid(int i,int j,int m,int n,vector<vector<char>> &board)
    {
        return i>=0 && j>=0 && i<m && j<n && board[i][j]!='#';
    }
    bool wordPresent(int i,int j,int idx,vector<vector<char>>& board, string word)
    {
        if(idx==word.length())
            return true;
        for(int k=0;k<4;k++)
        {
            int newRow=i+rows[k];
            int newCol=j+cols[k];
            if(isValid(newRow,newCol,board.size(),board[0].size(),board) && board[newRow][newCol]==word[idx])
            {
                char c=board[newRow][newCol];
                board[newRow][newCol]='#'; //mark as visited
                if(wordPresent(newRow,newCol,idx+1,board,word))
                    return true;
                board[newRow][newCol]=c; //backtrack
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>> board, string word) 
    {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0]){
                    char c=board[i][j];
                    board[i][j]='#'; //mark it as visited
                    if(wordPresent(i,j,1,board,word)){
                        return true;
                    }
                    board[i][j]=c;
                }
            }
        }
        return false;
    }
};
class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<string> s;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    string s1=to_string(board[i][j])+"at i="+to_string(i);
                    string s2=to_string(board[i][j])+"at j="+to_string(j);
                    int row=i/3;
                    int col=j/3;
                    string s3=to_string(board[i][j])+"at i="+to_string(row)+", j="+to_string(col);
                    if(s.find(s1)==s.end() && s.find(s2)==s.end() && s.find(s3)==s.end())
                    {
                        s.insert(s1);
                        s.insert(s2);
                        s.insert(s3);
                    }
                    else
                        return false;
                }                
            }
        }
        return true;
    }
};
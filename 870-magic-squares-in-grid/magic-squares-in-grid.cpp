class Solution {
private:
    string sequence = "2761834927618349";
    string revSequence = "9438167294381672";
    bool isMagicSquare(int r_idx, int c_idx, vector<vector<int>>& grid)
    {
        if(grid[r_idx+1][c_idx+1]!=5 || grid[r_idx][c_idx]%2!=0) 
            return false;

        int gridSum=5; //middle element

        string border="";
        vector<int> borderIndices={0,1,2,5,8,7,6,3};

        for(int i : borderIndices)
        {
            int num = grid[r_idx + i/3][c_idx + (i%3)];
            if(num > 9)
                return false;
            gridSum+=num;
            border+=to_string(num);
        }
        
        if(gridSum!=45)
            return false;

        return (sequence.find(border) != string::npos || revSequence.find(border) != string::npos);
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int ans=0;
        int rows=grid.size(), cols=grid[0].size();
        if(rows < 3 || cols < 3)
            return 0;
        for(int i=0;i<=rows-3;i++)
        {
            for(int j=0;j<=cols-3;j++)
            {
                if(isMagicSquare(i, j, grid))
                    ans++;
            }
        }
        return ans;
    }
};
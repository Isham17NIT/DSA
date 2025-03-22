class Solution {
public:
    int rows[4]={-1,0,1,0};
    int cols[4]={0,1,0,-1};
    bool isValid(int i,int j,int m,int n,vector<vector<int>>& image,int prevColor)
    {
        return i>=0 && i<m && j>=0 && j<n && image[i][j]==prevColor;
    }
    void dfsVisit(int sr,int sc,int m,int n,vector<vector<int>>& image,int prevColor,int color)
    {
        image[sr][sc]=color;
        for(int k=0;k<4;k++)
        {
            int i=sr+rows[k];
            int j=sc+cols[k];
            if(isValid(i,j,m,n,image,prevColor))
                dfsVisit(i,j,m,n,image,prevColor,color);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m=image.size();
        int n=image[0].size();
        int prevColor=image[sr][sc];
        if(prevColor==color) //original color == target color
            return image; //no changes will be made
        dfsVisit(sr,sc,m,n,image,prevColor,color);
        return image;
    }
};
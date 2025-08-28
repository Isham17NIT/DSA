class Solution 
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) 
    {
        unordered_map<int, vector<int>> m;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                m[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &it:m)
        {
            vector<int> v=it.second;
            if(it.first < 0) //top-right triangle
                sort(v.begin(),v.end(),greater<int>());
            else //bottom-left triangle
                sort(v.begin(),v.end());
            it.second=v;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                vector<int> v=m[i-j];
                grid[i][j]=v[v.size()-1];
                v.pop_back();
                m[i-j].pop_back();
            }
        }
        return grid;
    }
};
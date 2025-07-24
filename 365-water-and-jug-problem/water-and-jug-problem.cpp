class Solution {
public:
    bool canMeasureWater(int x, int y, int target) 
    {
        vector<vector<bool>> visited(x+1,vector<bool>(y+1,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;
        while(!q.empty())
        {
            auto [a,b] = q.front();
            q.pop();
            visited[a][b] = true;
            if(a==target || b==target || a+b==target)
                return true;
            if(!visited[0][b])
                q.push({0,b});
            if(!visited[a][0])
                q.push({a,0});
            if(!visited[x][b])
                q.push({x,b});
            if(!visited[a][y])
                q.push({a,y});
            if(!visited[max(0,a-(y-b))][min(y,a+b)])
                q.push({max(0,a-(y-b)), min(y,a+b)});
            if(!visited[min(x,a+b)][max(0,b-(x-a))])
                q.push({min(x,a+b), max(0,b-(x-a))});
        }
        return false;
    }
};
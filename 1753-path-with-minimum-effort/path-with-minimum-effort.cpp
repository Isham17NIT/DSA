class Solution 
{
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int r=heights.size();
        int c=heights[0].size();

        int x[4]={-1,0,1,0};
        int y[4]={0,1,0,-1};

        vector<vector<int>> dist(r,vector<int>(c,1e9));
        dist[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty())
        {
            pair<int,pair<int,int>> curr = pq.top();
            pq.pop();
            
            int diff = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;
            
            if(row==r-1 && col==c-1) //dest reached
                break;

            for(int i=0;i<4;i++)
            {
                int newRow = row + x[i];
                int newCol = col + y[i];
                if(newRow>=0 && newRow<r && newCol>=0 && newCol<c)
                {
                    int newEffort = max(diff, abs(heights[row][col] - heights[newRow][newCol]));
                    if(newEffort < dist[newRow][newCol])
                    {
                        dist[newRow][newCol] = newEffort;
                        pq.push({dist[newRow][newCol], {newRow, newCol}});
                    }
                }
            }
        }
        return dist[r-1][c-1];
    }
};
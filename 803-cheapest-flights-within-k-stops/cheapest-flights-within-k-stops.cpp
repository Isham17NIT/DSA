class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k)     
    {
        vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
        for(vector<int> v : flights)
        {
            graph[v[0]].push_back({v[1],v[2]});
        }

        queue<vector<int>> q; // {stops, node, dist}
        vector<int> cost(n,INT_MAX);
        cost[src] = 0;
        q.push({0,src,0});

        while(!q.empty())
        {
            vector<int> curr = q.front();
            q.pop();
            if(curr[0] > k)
                continue;
            for(pair<int,int> p : graph[curr[1]]) //iterate over the neighbours
            {
                if(curr[2] + p.second < cost[p.first])
                {
                    q.push({curr[0]+1, p.first, curr[2] + p.second});
                    cost[p.first] = curr[2] + p.second;
                }
            }
        }
        return cost[dest]==INT_MAX ? -1 : cost[dest];
    }
};